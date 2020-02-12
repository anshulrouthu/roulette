/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * dealer.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */


#include "dealer.h"
#include "player.h"
#include "roulette.h"
#include "outcome.h"
#include "bet.h"

Dealer::Dealer(Player& player, Roulette& roulette):
    mPlayer(player),
    mRoulette(roulette),
    mLogFile()
{
    mLogFile.open("RouletteLog.txt", std::ios::out);
}

Dealer::~Dealer()
{
    mLogFile.close();
}

GStatus Dealer::start()
{
    GStatus status;
    int quit;
    PlayerChoice choice;
    int betAmount;
    Outcome* outcome;
    Bet* bet;
    std::string logString;

    quit = false;

    while(!quit)
    {
        status = mPlayer.getChoice(choice);
        switch(choice)
        {
            case PCHOICE_PLACE_BET:
                bet = mPlayer.placeBet();

                outcome = mRoulette.spin();
                mPlayer.printMsg("The outcome is: \n");
                mPlayer.printMsg("\tNumber: " + outcome->getNumberString() + "\n");
                mPlayer.printMsg("\tColor: " + outcome->getColorString() + "\n");

                logString = "\nNumber: " + outcome->getNumberString() + "\tColor: " + outcome->getColorString();

                if(bet->satisfied(outcome))
                {
                    mPlayer.printMsg("\nYou have won: " + std::to_string(bet->getWinningAmount()) + "\n");
                    mPlayer.credit(bet->getWinningAmount());

                    logString += "\tWon:  " + std::to_string(bet->getWinningAmount());
                }
                else
                {
                    mPlayer.printMsg("\nYou have lost: " + std::to_string(bet->getBetAmount()) + "\n");
                    logString += "\tLost: " + std::to_string(bet->getBetAmount());
                }

                mLogFile.write(logString.c_str(), logString.size());

                delete bet;
                delete outcome;

                break;

            case PCHOICE_CHECK_BALANCE:
                mPlayer.printBalance();
                break;

            case PCHOICE_QUIT:
                quit = true;
                break;

            default:
                mPlayer.printMsg("Please enter a valid choice\n");
                break;
        }
    }

    return GSTATUS_SUCCESS;
}

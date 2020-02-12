/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * Player.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#include <iostream>
#include "player.h"
#include "colorbet.h"

Player::Player():
    mAmount(0),
    mInitialAmount(0)
{
    GStatus status;
    int amount;

    status = promptInput( PLAYER_WELCOME_MSG, amount );
    mAmount = amount;
    mInitialAmount = amount;
}

Player::~Player()
{
}

GStatus Player::getChoice(PlayerChoice& choice)
{
    int pchoice;
    GStatus status;

    status = promptInput(PLAYER_CHOICE_MSG, pchoice);

    switch(pchoice)
    {
        case 0:
            choice = PCHOICE_PLACE_BET;
            break;

        case 1:
            choice = PCHOICE_QUIT;
            break;

        case 2:
            choice = PCHOICE_CHECK_BALANCE;
            break;

        default:
            choice = PCHOICE_INVALID;
            break;
    }

    return GSTATUS_SUCCESS;
}

Bet* Player::placeBet()
{
    int choice;
    int amount;
    Bet* bet;

    promptInput( PLAYER_PLACE_BET_MSG, choice);
    promptInput(PLAYER_BET_AMOUNT_MSG, amount);

    switch(choice)
    {
        case 0:
            {
                bet = new ColorBet(amount, EVENT_COLOR_RED);
                debit(amount);
            }
            break;

        case 1:
            {
                bet = new ColorBet(amount, EVENT_COLOR_BLACK);
                debit(amount);
            }
            break;

        case 2:
            {
                bet = new ColorBet(amount, EVENT_COLOR_GREEN);
                debit(amount);
            }
            break;
    }

    return bet;
}

GStatus Player::printBalance()
{
    printMsg(PLAYER_BANK_BALANCE_MSG.c_str() + std::to_string(mAmount) + " ( " + std::to_string(mInitialAmount) + " )");
    return GSTATUS_SUCCESS;
}

GStatus Player::promptInput(const std::string& msg, int& choice)
{
    std::string buf;
    printMsg(msg);
    std::getline(std::cin, buf);

    choice = std::atoi(buf.c_str());

    return GSTATUS_SUCCESS;
}

GStatus Player::printMsg(std::string msg)
{
    printf("%s", msg.c_str());
    return GSTATUS_SUCCESS;
}

GStatus Player::debit(int amount)
{
    mAmount = mAmount - amount;
    return GSTATUS_SUCCESS;
}

GStatus Player::credit(int amount)
{
    mAmount = mAmount + amount;
    return GSTATUS_SUCCESS;
}


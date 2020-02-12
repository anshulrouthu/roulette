/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * player.h
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "game.h"
#include "bet.h"

const std::string PLAYER_WELCOME_MSG = "\nWelcome! Please enter your initial bank amount: ";
const std::string PLAYER_CHOICE_MSG = "\n0. Place a bet\n1. Quit\n2. Check balance\nPlease enter your choice: ";
const std::string PLAYER_BANK_BALANCE_MSG = "\nYour current balance: ";
const std::string PLAYER_PLACE_BET_MSG = "\n0. RED\n1. Black\n2. Green\nPlease place your bet: ";
const std::string PLAYER_BET_AMOUNT_MSG = "\nPlease enter your bet amount: ";
const std::string PLAYER_BET_CONFIRM_MSG = "\nYou have placed a bet ";

class Player
{
public:
    Player();
    ~Player();

    GStatus getChoice(PlayerChoice& choice);
    Bet* placeBet();
    GStatus printBalance();
    GStatus promptInput(const std::string& msg, int& choice );
    GStatus printMsg(const std::string msg);
    GStatus debit(int amount);
    GStatus credit(int amount);

private:
    int mAmount;
    int mInitialAmount;
};

#endif /* PLAYER_H_ */

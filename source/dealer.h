/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * dealer.h
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#ifndef DEALER_H_
#define DEALER_H_

#include "game.h"
#include "player.h"
#include "roulette.h"
#include <fstream>
#include <iostream>

class Dealer
{
public:
    Dealer(Player& player, Roulette& roulette);
    ~Dealer();

    GStatus start();

private:
    Player& mPlayer;
    Roulette& mRoulette;
    std::fstream mLogFile;
};

#endif /* DEALER_H_ */

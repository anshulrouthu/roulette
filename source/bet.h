/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * bet.h
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#ifndef BET_H_
#define BET_H_

#include "game.h"
#include "outcome.h"

class Bet
{
public:
    Bet(int amount);
    virtual ~Bet();

    virtual bool satisfied(Outcome* outcome) = 0;
    virtual int getWinningAmount() = 0;
    virtual int getBetAmount() = 0;

protected:
    int mAmount;
};

#endif /* BET_H_ */

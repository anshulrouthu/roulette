/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * colorbet.h
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#ifndef COLORBET_H_
#define COLORBET_H_

#include "bet.h"

class ColorBet :public Bet
{
public:
    ColorBet(int amount, EventColor color);
    ~ColorBet();

    virtual bool satisfied(Outcome* event);
    virtual int getWinningAmount();
    virtual int getBetAmount();

private:
    EventColor mColor;
};

#endif /* COLORBET_H_ */

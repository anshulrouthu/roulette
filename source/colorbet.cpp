/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * colorbet.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#include "colorbet.h"

ColorBet::ColorBet(int amount, EventColor color):
    Bet(amount),
    mColor(color)
{
}

ColorBet::~ColorBet()
{
}

bool ColorBet::satisfied(Outcome* outcome)
{
    bool ret_status;

    ret_status = false;

    if(outcome->getColor() == mColor)
    {
        ret_status = true;
    }

    return ret_status;
}

int ColorBet::getWinningAmount()
{
    return mAmount * 2;
}

int ColorBet::getBetAmount()
{
    return mAmount;
}
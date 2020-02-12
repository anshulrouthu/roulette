/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * outcome.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#include "outcome.h"

// 1-10,  19-28 Odd = red, even = black
// 11-18, 29-36 odd = black, even = red

Outcome::Outcome(int number):
    mNumber(number)
{
    if(((mNumber >= 1) && (mNumber <= 10)) || ((mNumber >= 19) && (mNumber <= 28)))
    {
        // if even number
        if((mNumber % 2) == 0)
        {
            mColor = EVENT_COLOR_BLACK;
        }
        else
        {
            mColor = EVENT_COLOR_RED;
        }
    }
    else if(((mNumber >= 11) && (mNumber <= 18)) || ((mNumber >= 29) && (mNumber <= 36)))
    {
        // if even number
        if((mNumber % 2) == 0)
        {
            mColor = EVENT_COLOR_RED;
        }
        else
        {
            mColor = EVENT_COLOR_BLACK;
        }
    }

    if((mNumber == 0) || (mNumber == 37))
    {
        mColor = EVENT_COLOR_GREEN;
    }
}

Outcome::~Outcome()
{
}

EventColor Outcome::getColor()
{
    return mColor;
}

int Outcome::getNumber()
{
    return mNumber;
}

std::string Outcome::getColorString()
{
    switch(mColor)
    {
    case EVENT_COLOR_RED:
        return "RED";

    case EVENT_COLOR_BLACK:
        return "BLACK";

    case EVENT_COLOR_GREEN:
        return "GREEN";

    default:
        return "INVALID";
    }

    return "";
}

std::string Outcome::getNumberString()
{
    return std::to_string(mNumber);
}

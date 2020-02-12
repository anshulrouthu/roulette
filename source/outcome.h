/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * outcome.h
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#ifndef OUTCOME_H_
#define OUTCOME_H_

#include "game.h"

class Outcome
{
public:
    Outcome(int number);
    ~Outcome();

    EventColor getColor();
    int getNumber();
    std::string getColorString();
    std::string getNumberString();

private:
    int mNumber;
    EventColor mColor;
};


#endif /* OUTCOME_H_ */

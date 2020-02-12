/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * roulette.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#include "roulette.h"

Roulette::Roulette()
{
}

Roulette::~Roulette()
{
}

Outcome* Roulette::spin()
{
    srand(time(NULL));
    Outcome* outcome = new Outcome(rand() % 38);
    return outcome;
}
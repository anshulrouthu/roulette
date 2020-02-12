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
#include <fstream>

Roulette::Roulette()
{
}

Roulette::~Roulette()
{
}

Outcome* Roulette::spin()
{
    std::fstream file;
    unsigned int buf;

    file.open("/dev/urandom", std::ios::in);
    file.read((char*)&buf, sizeof(int));
    file.close();

    Outcome* outcome = new Outcome(buf % 38);
    return outcome;
}
/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * roulette.h
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#ifndef ROULETTE_H_
#define ROULETTE_H_

#include "outcome.h"

class Roulette
{
public:

    Roulette();
    ~Roulette();

    Outcome* spin();
};

#endif /* ROULETTE_H_ */

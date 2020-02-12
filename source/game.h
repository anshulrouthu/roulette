/*******************************************************************************
 * Copyright (c) 2020 Anshul Routhu <anshul.m67@gmail.com>
 *
 * All rights reserved.
 *
 * This is a proprietary software. Unauthorized copying, modifying
 * or distributing of this software is strictly prohibited.
 *******************************************************************************/
/*
 * game.h
 *
 *  Created on: Feb 12, 2020
 *      Author: routhu
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <string>

typedef int GStatus;
enum
{
    GSTATUS_SUCCESS,
    GSTATUS_FAILURE,
};

typedef int PlayerChoice;
enum
{
    PCHOICE_PLACE_BET,
    PCHOICE_QUIT,
    PCHOICE_CHECK_BALANCE,
    PCHOICE_INVALID,
};

typedef int EventColor;
enum
{
    EVENT_COLOR_RED,
    EVENT_COLOR_BLACK,
    EVENT_COLOR_GREEN,
    EVENT_COLOR_COUNT,
    EVENT_COLOR_INVALID,
};
#endif /* GAME_H_ */

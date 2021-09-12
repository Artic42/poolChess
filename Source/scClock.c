/*
File Name:   scClock.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions to write the clock window on screen
Tested on:    Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "lib/Artic42.h"

#include "poolChess.h"
#include "scColors.h"
#include "scClock.h"

/***********************************************
*	Private Constants                          *
***********************************************/


/***********************************************
*	Private Structures                         *
***********************************************/


/***********************************************
*	Private Variables                          *
***********************************************/


/************************************************
*	Private Function Prtotype                   *
************************************************/

void drawWhiteTurn (void);
void drawBlackTurn (void);

/***********************************************
*	Code                                       *
***********************************************/

void drawClocks (void)
{
    wattr_set (clockWindow, 0, MAIN, NULL);
    mvwprintw (clockWindow, CLOCK_MARGIN_Y, CLOCK_MARGIN_X, "GAME CLOCK");
    drawTurn ();
    drawTime (WHITE);
    drawTime (BLACK);
}

void drawTurn (void)
{
    if (g_s_moves.moveAmount%2 == 0)    { drawWhiteTurn(); }
    else                                { drawBlackTurn(); }
}

void drawTime (int8b color)
{
    long time, minutes, seconds;

    if (color == WHITE)
    {
        time = g_s_white.timeLeft;
        wmove (clockWindow, CLOCK_MARGIN_Y_3RD, CLOCK_MARGIN_X);
    }
    else
    {
        time = g_s_black.timeLeft;
        wmove (clockWindow, CLOCK_MARGIN_Y_3RD, CLOCK_MARGIN_BLACK_X);
    }
    wattr_set (clockWindow, 0, MAIN, NULL);

    minutes = time / 60;
    seconds = time % 60;

    if (minutes >= 10) { wprintw(clockWindow, "%i:", minutes); }
    else               { wprintw(clockWindow, "0%i:", minutes); }

    if (seconds >= 10) { wprintw(clockWindow, "%i", seconds); }
    else               { wprintw(clockWindow, "0%i", seconds); }

    wrefresh (clockWindow);
}

void drawWhiteTurn (void)
{
    wattr_set (clockWindow, 0, INVERSE, NULL);
    mvwprintw (clockWindow, CLOCK_MARGIN_Y_2ND, CLOCK_MARGIN_X, "WHITE");
    wattr_set (clockWindow, 0, MAIN, NULL);
    mvwprintw (clockWindow, CLOCK_MARGIN_Y_2ND, CLOCK_MARGIN_BLACK_X, "BLACK");
    wrefresh (clockWindow);
}

void drawBlackTurn (void)
{
    wattr_set (clockWindow, 0, MAIN, NULL);
    mvwprintw (clockWindow, CLOCK_MARGIN_Y + 2, CLOCK_MARGIN_X, "WHITE");
    wattr_set (clockWindow, 0, INVERSE, NULL);
    mvwprintw (clockWindow, CLOCK_MARGIN_Y + 2, CLOCK_MARGIN_BLACK_X, "BLACK");
    wrefresh (clockWindow);
}
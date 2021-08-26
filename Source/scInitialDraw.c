/*
File Name:   scInitialDraw.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions that draw the initial screen game
Tested on:   Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include <ncurses.h>

#include "scColors.h"
#include "poolChess.h"

/************************************************
*	Private Function Prtotype                   *
************************************************/

void defineColors (void);
void initializeNcurses (void);
WINDOW *createWindowCentered (int width, int height);

/***********************************************
*	Private Structures                         *
***********************************************/

/***********************************************
*	Private Constants                          *
***********************************************/

#define SCREEN_HEIGHT 27
#define SCREEN_WIDTH 64

/***********************************************
*	Private Variables                          *
***********************************************/

/***********************************************
*	Code                                       *
***********************************************/

void scInitialDraw (void)
{
    initializeNcurses ();
    mainWindow = createWindowCentered (SCREEN_WIDTH, SCREEN_HEIGHT);
    //wborder (mainWindow, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    wbkgdset (mainWindow, WH_P_WH_S);
    waddstr (mainWindow, "Hello World");

    refresh();
}

void defineColors (void)
{
    init_color (WH_P, WH_P_R, WH_P_G, WH_P_B);
    init_color (BK_P, BK_P_R, BK_P_G, BK_P_B);
    init_color (WH_S, WH_S_R, WH_S_G, WH_S_B);
    init_color (BK_S, BK_S_R, BK_S_G, BK_S_B);
    init_color (BACKGROUND, 0, 0, 0);
    init_color (FOREGROUND, 1000, 1000, 1000);

    init_pair (MAIN, FOREGROUND, BACKGROUND);
    init_pair (WH_P_WH_S, WH_P, WH_S);
    init_pair (WH_P_BK_S, WH_P, BK_S);
    init_pair (BK_P_WH_S, BK_P, WH_S);
    init_pair (BK_P_BK_S, BK_P, BK_S);
}

void initializeNcurses (void)
{
    initscr ();
    if (has_colors()) { start_color (); }
    defineColors ();
}

WINDOW *createWindowCentered (int width, int height)
{
    WINDOW *result;
    long row, col;
    getmaxyx (stdscr, row, col);

    result = newwin (height, width, (row-height)/2, (col-width)/2);
    return result;
}
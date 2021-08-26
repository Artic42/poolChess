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

#include <scColors.h>

/************************************************
*	Private Function Prtotype                   *
************************************************/

void defineColors (void);

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
    initscr ();
    start_color ();

    defineColors ();

    attr_set (0, MAIN, NULL);
    addstr ("This is the main text\n");
    attr_set (A_BOLD, WH_P_WH_S, NULL);
    addstr ("This is a white piece");
    attr_set (A_BOLD, WH_P_BK_S, NULL);
    addstr ("This is a white piece\n");
    attr_set (A_BOLD, BK_P_BK_S, NULL);
    addstr ("This is a black piece");
    attr_set (A_BOLD, BK_P_WH_S, NULL);
    addstr ("This is a black piece");

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
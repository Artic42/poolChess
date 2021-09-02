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
#include "dtRead.h"
#include "scInitialDraw.h"

/************************************************
*	Private Function Prtotype                   *
************************************************/

void defineColors (void);
void initializeNcurses (void);
void drawBoard (void);
void drawSquare (int startY, int startX, int8b color);
void drawColumns (void);
void drawLines (void);
void drawClocks (void);
void drawOrder (void);
WINDOW *createWindowCentered (int width, int height);
WINDOW *createWindow (int width, int height, int posY, int posX);
WINDOW *createSubWindow (WINDOW *origWindow, int width, int height, int posY, int posX);

/***********************************************
*	Private Structures                         *
***********************************************/

/***********************************************
*	Private Constants                          *
***********************************************/


/***********************************************
*	Private Variables                          *
***********************************************/

/***********************************************
*	Code                                       *
***********************************************/

void scInitialDraw (void)
{
    initializeNcurses ();
    refresh ();
    mainWindow = createWindowCentered (SCREEN_WIDTH, SCREEN_HEIGHT);
    wrefresh (mainWindow);
    clockWindow = createSubWindow (mainWindow, CLOCK_HEIGHT, CLOCK_WIDTH, CLOCK_POS_Y, CLOCK_POS_X);
    wrefresh (clockWindow);
    auxWindow = createSubWindow (mainWindow, AUX_HEIGHT, AUX_WIDTH, AUX_POS_Y, AUX_POS_X);
    wrefresh (auxWindow);
    orderWindow = createSubWindow (mainWindow, ORDER_HEIGHT, ORDER_WIDTH, ORDER_POS_Y, ORDER_POS_X);
    wrefresh (orderWindow);


    drawBoard ();
    drawColumns ();
    drawLines ();

    drawClocks ();
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
    init_pair (ALARM_PAIR, BACKGROUND, FOREGROUND);
    init_pair (WARNING_PAIR, BACKGROUND, COLOR_YELLOW);
}

void initializeNcurses (void)
{
    initscr ();
    if (has_colors()) { start_color (); }
    defineColors ();
}

void drawBoard (void)
{
    for (int col=0; col<=7; col++)
    {
        for (int row=1; row<=8; row++)
        {
            int posY, posX;
            posY = BOARD_MARGIN_Y + (SQUARE_HEIGHT * (row - 1));
            posX = BOARD_MARGIN_X + (SQUARE_WIDTH * col);
            drawSquare (posY, posX, getSquareColor ('H' - col, row));
        }
    }
    wrefresh (mainWindow);
}

void drawSquare (int startY, int startX, int8b color)
{
    if (color == WHITE) { wattr_set (mainWindow, 0, WH_P_WH_S, NULL); }
    else                { wattr_set (mainWindow, 0, BK_P_BK_S, NULL); }

    for (int i=0; i<=2; i++) { mvwprintw (mainWindow, startY + i, startX, "    "); }
}

void drawColumns (void)
{
    wattr_set (mainWindow, 0, MAIN, NULL);
    for (int i = 0; i<=7; i++)
    {
        mvwprintw (mainWindow, COLUMN_POS_Y, BOARD_MARGIN_X + 1 + (SQUARE_WIDTH * i), "%c", 'A'+i);
    }
    wrefresh (mainWindow);
}

void drawLines (void)
{
    wattr_set (mainWindow, 0, MAIN, NULL);
    for (int i = 0; i<=7; i++)
    {
        mvwprintw (mainWindow, BOARD_MARGIN_Y + 1 + (SQUARE_HEIGHT * i), LINE_POS_X, "%i", 8-i);
    }
    wrefresh (mainWindow);
}

void drawClocks (void)
{
    wattr_set (clockWindow, 0, MAIN, NULL);
    mvwprintw (clockWindow, CLOCK_MARGIN_Y, CLOCK_MARGIN_X, "GAME CLOCK");
    mvwprintw (clockWindow, CLOCK_MARGIN_Y + 2, CLOCK_MARGIN_X, "WHITE");
    mvwprintw (clockWindow, CLOCK_MARGIN_Y + 4, CLOCK_MARGIN_X, "0%i:0%i", g_s_white.timeLeft / 60, g_s_white.timeLeft % 60);
    mvwprintw (clockWindow, CLOCK_MARGIN_Y + 2, CLOCK_MARGIN_BLACK_X, "BLACK");
    mvwprintw (clockWindow, CLOCK_MARGIN_Y + 4, CLOCK_MARGIN_BLACK_X, "0%i:0%i", g_s_black.timeLeft / 60, g_s_black.timeLeft % 60);
    wrefresh (clockWindow);
}

WINDOW *createWindowCentered (int width, int height)
{
    long row, col;
    getmaxyx (stdscr, row, col);
    return createWindow (height, width, (row-height)/2, (col-width)/2);
}

WINDOW *createWindow (int height, int width, int posY, int posX)
{
    WINDOW *result;
    
    result = newwin (height, width, posY, posX);
    wborder (result, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    return result;
}

WINDOW *createSubWindow (WINDOW *origWindow, int height, int width, int posY, int posX)
{
    WINDOW *result;
    
    result = derwin (origWindow, height, width, posY, posX);
    wborder (result, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    return result;
}
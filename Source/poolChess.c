/*
File Name:   poolChess.h
//
Compiler:    gcc
Author:      Artic42
Description: General header file for pool chess
Tested on:    Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include <unistd.h>
#include <ncurses.h>

#include "lib/Artic42.h"
#include "poolChess.h"
#include "dtInitialize.h"
#include "scInitialDraw.h"
#include "scPieceDraw.h"
#include "scOrder.h"
#include "scClock.h"

/************************************************
*	Private Function Prtotype                   *
************************************************/



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
*	Global variables                            *
************************************************/

struct s_piece g_s_pieces [32];
struct s_color g_s_white, g_s_black;
struct s_moveHistory g_s_moves;
WINDOW *mainWindow, *clockWindow, *orderWindow, *auxWindow;

/***********************************************
*	Code                                       *
***********************************************/

int main (void)
{
    dataInitializeNewGame ();
    scInitialDraw ();
    drawAllPieces ();
    while (BTRUE)
    {
        makeMove ();
        g_s_moves.moveAmount++;
        drawTurn ();
    }

    endwin ();
    return 0;
}

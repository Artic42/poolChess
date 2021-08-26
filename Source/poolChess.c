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

#include "lib/Artic42.h"
#include "poolChess.h"
#include "initializeData.h"

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

/***********************************************
*	Code                                       *
***********************************************/

int main (void)
{
    dataInitializeNewGame ();
    
    return 0;
}

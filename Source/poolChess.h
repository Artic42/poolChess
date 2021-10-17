/*
File Name:   poolChess.h
//
Compiler:    gcc
Author:      Artic42
Description: General header file for pool chess
Tested on:    Windows Subsystem for Linux
*/

#ifndef POOL_CHESS_H
#define POOL_CHESS_H

#include "lib/Artic42.h"
#include "ncurses.h"

/************************************************
*   Public constants                            *
************************************************/

#define EMPTY_SQUARE 32

//Piece types
#define KING 'K'
#define QUEEN 'Q'
#define ROOK 'R'
#define BISHOP 'B'
#define KNIGHT 'N'
#define PAWN 'P'

//Piece colors
#define WHITE 0X01
#define BLACK 0X02



/************************************************
*   Public strucutres                           *
************************************************/

struct s_coordinate {
    int8b row;
    char column;
};

struct s_color {
    boolean isHuman;
    long timeLeft;
};

struct s_piece {
    int8b type;
    int8b color;
    struct s_coordinate Position;
    boolean Moved;
    boolean inBoard;
};

struct s_move {
    int8b ID;
    struct s_coordinate start;
    struct s_coordinate destination;
    int8b eatenID;
    int8b direction;
    int8b module;
    int8b movedPieceType;
    int8b movedPieceColor;
    struct s_move *nxt;
    struct s_move *prv;
};

struct s_moveHistory {
    int moveAmount;
    struct s_move *firstMove;
    struct s_move *lastMove;
};

/************************************************
*	Global variables                            *
************************************************/

extern struct s_piece g_s_pieces [32];
extern struct s_color g_s_white, g_s_black;
extern struct s_moveHistory g_s_moves;
extern WINDOW *mainWindow, *clockWindow, *orderWindow, *auxWindow;


#endif
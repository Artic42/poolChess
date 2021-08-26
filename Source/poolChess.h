/*
File Name:   poolChess.h
//
Compiler:    gcc
Author:      Artic42
Description: General header file for pool chess
Tested on:    Windows Subsystem for Linux
*/

#include "lib/Artic42.h"

/************************************************
*   Public constants                            *
************************************************/

//Piece types
#define KING 0x01
#define QUEEN 0x02
#define ROOK 0x03
#define BISHOP 0x04
#define KNIGHT 0x05
#define PAWN 0x06

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
    bool isHuman;
    long timeLeft;
};

struct s_piece {
    int8b type;
    int8b color;
    struct s_coordinate Position;
    bool Moved;
    bool inBoard;
};

struct s_move {
    int8b ID;
    struct s_coordinate start;
    struct s_coordinate destination;
    int8b eatenID;
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
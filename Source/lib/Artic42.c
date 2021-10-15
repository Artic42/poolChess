/*
File Name:   Artic42.c
//
Compiler:    gcc
Author:      Artic42
Description: Header were I include a series of common functions that I use in all projects
Tested on:   Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "lib/Artic42.h"

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



/***********************************************
*	Code                                       *
***********************************************/

char makeUpperCase (char character)
{
    if (characterIsLowerCase (character)) { return character - 32; }
    else                                  { return -1;             }
}

char makeLowerCase (char character)
{
    if (characterIsUpperCase (character)) { return character + 32; }
    else                                  { return -1;             }
}

int8b makeCharInt (char character)
{
    return character - 48;
}

boolean characterBetweenLetters (char character, char upperLimit, char lowerLimit)
{
    return (character <= upperLimit) && (character >= lowerLimit);
}

boolean characterIsLetter (char character)
{
    return characterIsLowerCase (character) || characterIsUpperCase (character);
}

boolean characterIsLowerCase (char character)
{
    return characterBetweenLetters (character, 'z', 'a');
}

boolean characterIsUpperCase (char character)
{
    return characterBetweenLetters (character, 'Z', 'A');
}

boolean characterIsNumber (char character)
{
    return characterBetweenLetters (character, '9', '0');
}



int intAbsolute (int value)
{
    if (value < 0)  { return value * (-1); }
    else            { return value; }
}

int intGiveMax (int value1, int value2)
{
    if (value1 < value2) { return value2; }
    else                 { return value1; }
}

int intGiveMin (int value1, int value2)
{
    if (value1 > value2) { return value2; }
    else                 { return value1; }
}
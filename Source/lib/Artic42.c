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
    if (characterIsLowerCase()) { return character - 32; }
    else                        { return -1;             }
}

char makeLowerCase (char character)
{
    if (characterIsUpperCase()) { return character + 32; }
    else                        { return -1;             }
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
    characterBetweenLetters (character, 'z', 'a');
}

boolean characterIsUpperCase (char character)
{
    characterBetweenLetters (character, 'Z', 'A');
}

boolean characterIsNumber (char character)
{
    characterBetweenLetters (character, '9', '0');
}
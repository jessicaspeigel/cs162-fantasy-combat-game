/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/

#include "Die.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

Die::Die(int sides)
{
    // Initialize roll value
    rollValue = -1;
    // Set the sides
    setSides(sides);

}

/****************************************************
** DESTRUCTORS
****************************************************/

Die::~Die()
{
    // Compiler complains if I don't have this :(
}

/****************************************************
** GETTERS / SETTERS
****************************************************/

void Die::setSides(int sides)
{
    this->sides = sides;
}

int Die::getSides()
{
    return sides;
}

int Die::getRollValue()
{
    return rollValue;
}

/****************************************************
** Description: Rolls the die and returns the result
****************************************************/

int Die::roll()
{
    rollValue = rand() % getSides() + 1;
    return rollValue;
}
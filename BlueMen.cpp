/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: blue men class implementation
****************************************************/

#include "BlueMen.hpp"

BlueMen::BlueMen() : Character("Blue Men", 3, 12, 0)
{
    attackRoll.numDice = 2, defenseRoll.numDice = 3;
    attackRoll.numDiceSides = 10, defenseRoll.numDiceSides = 6;
}

BlueMen::~BlueMen()
{

}

int BlueMen::attack(Character *defender) {
    return 0;
}

void BlueMen::defend(Character *attacker, int attack) {
}

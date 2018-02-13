/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: blue men class implementation
****************************************************/

#include "BlueMen.hpp"

BlueMen::BlueMen() : Character("Blue Men", 3, 12)
{
    roll_t attack, defense;
    attack.numDice = 2, defense.numDice = 3;
    attack.numDiceSides = 10, defense.numDiceSides = 6;
    setAttack(attack);
    setDefense(defense);
}

BlueMen::~BlueMen()
{

}

int BlueMen::attack() {
    return 0;
}

int BlueMen::defend() {
    return 0;
}

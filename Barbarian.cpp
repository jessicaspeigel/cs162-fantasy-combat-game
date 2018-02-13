/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: barbarian class implementation
****************************************************/

#include "Barbarian.hpp"

Barbarian::Barbarian() : Character("Barbarian", 0, 12)
{
    roll_t attack, defense;
    attack.numDice = 2, defense.numDice = 2;
    attack.numDiceSides = 6, defense.numDiceSides = 6;
    setAttack(attack);
    setDefense(defense);
}

Barbarian::~Barbarian()
{

}

int Barbarian::attack() {
    return 0;
}

int Barbarian::defend() {
    return 0;
}

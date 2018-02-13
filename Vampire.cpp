/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: vampire class implementation
****************************************************/

#include "Vampire.hpp"

Vampire::Vampire() : Character("Vampire", 1, 18)
{
    roll_t attack, defense;
    attack.numDice = 1, defense.numDice = 1;
    attack.numDiceSides = 12, defense.numDiceSides = 6;
    setAttack(attack);
    setDefense(defense);
}

Vampire::~Vampire()
{

}

int Vampire::attack() {
    return 0;
}

int Vampire::defend() {
    return 0;
}

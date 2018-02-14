/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: vampire class implementation
****************************************************/

#include "Vampire.hpp"

Vampire::Vampire() : Character("Vampire", 1, 18, 0)
{
    attackRoll.numDice = 1, defenseRoll.numDice = 1;
    attackRoll.numDiceSides = 12, defenseRoll.numDiceSides = 6;
}

Vampire::~Vampire()
{

}

int Vampire::attack(Character *defender) {
    return 0;
}

void Vampire::defend(Character *attacker, int attack) {
}

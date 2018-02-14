/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: medusa class implementation
****************************************************/

#include "Medusa.hpp"

Medusa::Medusa() : Character("Medusa", 3, 8, 0)
{
    attackRoll.numDice = 2, defenseRoll.numDice = 1;
    attackRoll.numDiceSides = 6, defenseRoll.numDiceSides = 6;
}

Medusa::~Medusa()
{

}

int Medusa::attack(Character *defender) {
    return 0;
}

void Medusa::defend(Character *attacker, int attack) {

}

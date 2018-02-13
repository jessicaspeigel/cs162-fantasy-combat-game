/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: medusa class implementation
****************************************************/

#include "Medusa.hpp"

Medusa::Medusa() : Character("Medusa", 3, 8)
{
    roll_t attack, defense;
    attack.numDice = 2, defense.numDice = 1;
    attack.numDiceSides = 6, defense.numDiceSides = 6;
    setAttack(attack);
    setDefense(defense);
}

Medusa::~Medusa()
{

}

int Medusa::attack() {
    return 0;
}

int Medusa::defend() {
    return 0;
}

/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: harry potter class implementation
****************************************************/

#include "HarryPotter.hpp"

HarryPotter::HarryPotter() : Character("Harry Potter", 0, 10, 0)
{
    attackRoll.numDice = 2, defenseRoll.numDice = 2;
    attackRoll.numDiceSides = 6, defenseRoll.numDiceSides = 6;
}

HarryPotter::~HarryPotter()
{

}

int HarryPotter::attack(Character *defender) {
    return 0;
}

void HarryPotter::defend(Character *attacker, int attack) {
}

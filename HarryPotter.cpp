/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: harry potter class implementation
****************************************************/

#include "HarryPotter.hpp"

HarryPotter::HarryPotter() : Character("Harry Potter", 0, 10)
{
    roll_t attack, defense;
    attack.numDice = 2, defense.numDice = 2;
    attack.numDiceSides = 6, defense.numDiceSides = 6;
    setAttack(attack);
    setDefense(defense);
}

HarryPotter::~HarryPotter()
{

}

int HarryPotter::attack() {
    return 0;
}

int HarryPotter::defend() {
    return 0;
}

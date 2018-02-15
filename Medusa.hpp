/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: medusa class header
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_MEDUSA_HPP
#define CS162_FANTASY_COMBAT_GAME_MEDUSA_HPP

#include "Character.hpp"

class Medusa: public Character {
private:

public:
    Medusa();
    ~Medusa();
    int attack(Character *defender);
    void defend(Character *attacker, int attack);
};

#endif //CS162_FANTASY_COMBAT_GAME_MEDUSA_HPP

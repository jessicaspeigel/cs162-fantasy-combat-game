/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: vampire class header
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_VAMPIRE_HPP
#define CS162_FANTASY_COMBAT_GAME_VAMPIRE_HPP

#include "Character.hpp"

class Vampire: public Character {
private:

public:
    Vampire();
    ~Vampire();
    int attack(Character *defender);
    void defend(Character *attacker, int attack);
};

#endif //CS162_FANTASY_COMBAT_GAME_VAMPIRE_HPP

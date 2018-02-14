/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: blue men class header
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_BLUEMEN_HPP
#define CS162_FANTASY_COMBAT_GAME_BLUEMEN_HPP

#include "Character.hpp"

class BlueMen: public Character {
private:

public:
    BlueMen();
    virtual ~BlueMen();
    int attack(Character *defender);
    void defend(Character *attacker, int attack);
};

#endif //CS162_FANTASY_COMBAT_GAME_BLUEMEN_HPP

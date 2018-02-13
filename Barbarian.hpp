/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: barbarian class header
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_BARBARIAN_HPP
#define CS162_FANTASY_COMBAT_GAME_BARBARIAN_HPP

#include "Character.hpp"

class Barbarian: public Character {
private:

public:
    Barbarian();
    virtual ~Barbarian();
    int attack();
    int defend();
};

#endif //CS162_FANTASY_COMBAT_GAME_BARBARIAN_HPP

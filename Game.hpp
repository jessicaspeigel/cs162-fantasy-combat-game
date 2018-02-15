/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: header for game class
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_GAME_HPP
#define CS162_FANTASY_COMBAT_GAME_GAME_HPP

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Die.hpp"
#include "Menu.hpp"

class Game {
    private:
        Character* player1;
        Character* player2;
        void setPlayer1(Character &player);
        void setPlayer2(Character &player);
        int round;
        void startGame();
        bool runRound();

    public:
        Game();
        ~Game();
        Character* getPlayer1();
        Character* getPlayer2();
};

#endif //CS162_FANTASY_COMBAT_GAME_GAME_HPP

/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_CHARACTER_HPP
#define CS162_FANTASY_COMBAT_GAME_CHARACTER_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include "Die.hpp"

struct roll_t {
    int numDice;
    int numDiceSides;
};

class Character {
    protected:
        std::string name;
        roll_t attackRoll;
        roll_t defenseRoll;
        int armor;
        int strength;
        int numLives;
        bool isDead;
        virtual void die();
        Die** attackDice;
        Die** defenseDice;

    public:
        Character(std::string name, int armor, int strength, int numLives);
        virtual ~Character() {};
        virtual int attack(Character *defender) = 0;
        virtual void defend(Character *attacker, int attack) = 0;
        int getArmor();
        int getStrength();
        bool isAlive();
        void setStrength(int strength);
        roll_t getAttack();
        roll_t getDefense();
        std::string getName();

};


#endif //CS162_FANTASY_COMBAT_GAME_CHARACTER_HPP

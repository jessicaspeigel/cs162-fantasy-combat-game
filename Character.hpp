/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_CHARACTER_HPP
#define CS162_FANTASY_COMBAT_GAME_CHARACTER_HPP

#include <iostream>
#include <string>

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

    public:
        Character(std::string name, int armor, int strength);
        virtual ~Character() {};
        virtual int attack() = 0;
        virtual int defend() = 0;
        int getArmor();
        int getStrength();
        roll_t getAttack();
        roll_t getDefense();
        void setAttack(roll_t attackRoll);
        void setDefense(roll_t defenseRoll);
        std::string getName();

};


#endif //CS162_FANTASY_COMBAT_GAME_CHARACTER_HPP

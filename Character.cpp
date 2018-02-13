/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/
#include "Character.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Character::Character(std::string name, int armor, int strength) {
    this->name = name;
    this->armor = armor;
    this->strength = strength;
}

int Character::getArmor() {
    return armor;
}

int Character::getStrength() {
    return strength;
}

roll_t Character::getAttack() {
    return attackRoll;
}

roll_t Character::getDefense() {
    return defenseRoll;
}

void Character::setAttack(roll_t attackRoll) {
    this->attackRoll = attackRoll;
}

void Character::setDefense(roll_t defenseRoll) {
    this->defenseRoll = defenseRoll;
}

string Character::getName() {
    return this->name;
}

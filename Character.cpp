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

Character::Character(std::string name, int armor, int strength, int numLives) {
    this->name = name;
    this->armor = armor;
    this->strength = strength;
    this->numLives = numLives;
    this->isDead = false;
}

Character::~Character() {

}


int Character::getArmor() {
    return armor;
}

int Character::getStrength() {
    return strength;
}

void Character::setStrength(int strength) {
    this->strength = strength;
    if (strength <= 0) {
        death();
    }
}

roll_t Character::getAttack() {
    return attackRoll;
}

roll_t Character::getDefense() {
    return defenseRoll;
}

string Character::getName() {
    return this->name;
}

void Character::death() {
    isDead = true;
}

bool Character::isAlive() {
    return !isDead;
}

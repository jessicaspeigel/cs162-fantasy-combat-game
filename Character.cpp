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
    this->currentStrength = strength;
    this->startStrength = strength;
    this->numLives = numLives;
    this->isDead = false;
    this->currentLife = 0;
}

Character::~Character() {

}


int Character::getArmor() {
    return armor;
}

int Character::getStrength() {
    return currentStrength;
}

void Character::setStrength(int strength) {
    this->currentStrength = strength;
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
    return name;
}

void Character::death() {
    // Increment the current life
    currentLife++;
    // Check to see if they're out of lives
    if (currentLife == numLives) {
        isDead = true;
    } else {
        // Tell the user what happened and how many lives are left
        cout << getName() << " has lost a life. They have " << (numLives - currentLife) << " life left." << endl;
        resetStrength();
    }
}

bool Character::isAlive() {
    return !isDead;
}

void Character::resetStrength() {
    setStrength(startStrength);
}

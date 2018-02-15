/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: blue men class implementation
****************************************************/

#include "BlueMen.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

BlueMen::BlueMen() : Character("Blue Men", 3, 12, 1)
{
    attackRoll.numDice = 2, defenseRoll.numDice = 3;
    attackRoll.numDiceSides = 10, defenseRoll.numDiceSides = 6;
    // Set up the array for attack dice
    attackDice = new Die*[attackRoll.numDice];
    for (int i = 0; i < attackRoll.numDice; i++) {
        attackDice[i] = new Die(attackRoll.numDiceSides);
    }
    // Set up the array for defense dice
    defenseDice = new Die*[defenseRoll.numDice];
    for (int i = 0; i < defenseRoll.numDice; i++) {
        defenseDice[i] = new Die(defenseRoll.numDiceSides);
    }
}

BlueMen::~BlueMen()
{
    // Clean up the array for attack dice
    for (int i = 0; i < attackRoll.numDice; i++) {
        delete attackDice[i];
    }
    delete [] attackDice;
    // Clean up the array for defense dice
    for (int i = 0; i < defenseRoll.numDice; i++) {
        delete defenseDice[i];
    }
    delete [] defenseDice;
}

int BlueMen::attack(Character *defender) {
    // Print out the attack information
    cout << "Attacker type: " << getName() << endl;
    cout << "Defender type: " << defender->getName() << ", Armor: " << defender->getArmor() << ", Strength: " << defender->getStrength() << endl;
    cout << getName() << "'s attack dice roll: ";

    int attackTotal = 0;
    int currentRoll = 0;
    for (int i = 0; i < attackRoll.numDice; i++) {
        currentRoll  = attackDice[i]->roll();
        attackTotal += currentRoll;
        // Print the roll for the current die
        cout << " die " << (i + 1) << " (" << currentRoll << ")";
    }
    cout << " for an attack total of " << attackTotal << endl;
    return attackTotal;
}

void BlueMen::defend(int attackScore) {
    cout << getName() << "'s defense dice roll: ";
    int defenseTotal = 0;
    int currentRoll = 0;
    for (int i = 0; i < defenseRoll.numDice; i++) {
        currentRoll  = defenseDice[i]->roll();
        defenseTotal += currentRoll;
        // Print the roll for the current die
        cout << " die " << (i + 1) << " (" << currentRoll << ")";
    }
    cout << " for a defense total of " << defenseTotal << endl;

    // Calculate damage and adjust strength
    int damage = max(attackScore - defenseTotal - this->getArmor(), 0);
    int newStrength = this->getStrength() - damage;
    this->setStrength(newStrength);

    cout << "Total inflicted damage: " << damage << endl;
    cout << this->getName() << "'s new strength: " << this->getStrength() << endl;
    cout << endl;
}

void BlueMen::setStrength(int strength) {
    // Call the parent
    Character::setStrength(strength);

    // See if we have to remove any defense dice
    int newDiceNum = 0;

    // Strength between 9-12 = 3 die / between 5-8 = 2 die / between 1-4 = 1 die
    if (strength > 8 && strength <= 12) {
        newDiceNum = 3;
    } else if (strength > 4 && strength <= 8) {
        newDiceNum = 2;
    } else if (strength > 0 && strength <= 4) {
        newDiceNum = 1;
    }

    if (newDiceNum != defenseRoll.numDice) {
        // Clean up the array for defense dice
        for (int i = 0; i < defenseRoll.numDice; i++) {
            delete defenseDice[i];
        }
        delete [] defenseDice;
        // Reset the number of dice to the new value
        defenseRoll.numDice = newDiceNum;
        // Repopulate the array
        defenseDice = new Die*[defenseRoll.numDice];
        for (int i = 0; i < defenseRoll.numDice; i++) {
            defenseDice[i] = new Die(defenseRoll.numDiceSides);
        }
    }
}

/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: vampire class implementation
****************************************************/

#include "Vampire.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

Vampire::Vampire() : Character("Vampire", 1, 18, 1)
{
    attackRoll.numDice = 1, defenseRoll.numDice = 1;
    attackRoll.numDiceSides = 12, defenseRoll.numDiceSides = 6;
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

Vampire::~Vampire()
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

int Vampire::attack(Character *defender) {
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

void Vampire::defend(int attackScore) {
    // See if the Vampire can charm his opponent into not attacking
    int charmed = rand() % 2;
    if (charmed == 1) {
        // The attacker didn't attack.
        cout << getName() << " charmed his opponent into not attacking! No damage inflicted." << endl;
    } else {
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
    }
    cout << endl;
}

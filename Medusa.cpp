/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: medusa class implementation
****************************************************/

#include "Medusa.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

Medusa::Medusa() : Character("Medusa", 3, 8, 1)
{
    attackRoll.numDice = 2, defenseRoll.numDice = 1;
    attackRoll.numDiceSides = 6, defenseRoll.numDiceSides = 6;
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

Medusa::~Medusa()
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

int Medusa::attack(Character *defender) {
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
    if (attackTotal == 12) {
        // Medusa's glare is activated
        cout << "Glare activated! " << getName() << " petrifies " << defender->getName() << "." << endl;
        // Sets the attack so high no one can counter it
        attackTotal = 10000;
    }
    return attackTotal;
}

void Medusa::defend(Character *attacker, int attackScore) {
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

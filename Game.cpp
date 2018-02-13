/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/

#include "Game.hpp"
#include "Die.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

Game::Game() {
    // Initialize player pointers to null
    player1 = nullptr, player2 = nullptr;
    // Default constructor prompts user to select characters
    int p1Choice = 0, p2Choice = 0;
    vector<string> charMenuItems = {"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
    Menu charMenu(charMenuItems);
    // Prompt for player 1
    charMenu.setPromptText("Select a character for player 1");
    p1Choice = charMenu.showMenu();
    // Create player1
    // Create player2
    if (p1Choice == 1) {
        // Vampire
        Vampire p1;
        setPlayer1(p1);
    } else if (p1Choice == 2) {
        // Barbarian
        Barbarian p1;
        setPlayer1(p1);
    } else if (p1Choice == 3) {
        // Blue Men
        BlueMen p1;
        setPlayer1(p1);
    } else if (p1Choice == 4) {
        // Medusa
        Medusa p1;
        setPlayer1(p1);
    } else if (p1Choice == 5) {
        // Harry Potter
        HarryPotter p1;
        setPlayer1(p1);
    }
    // Prompt for player 2
    charMenu.setPromptText("Select a character for player 2");
    p2Choice = charMenu.showMenu();
    // Create player2
    if (p2Choice == 1) {
        // Vampire
        Vampire p2;
        setPlayer2(p2);
    } else if (p2Choice == 2) {
        // Barbarian
        Barbarian p2;
        setPlayer2(p2);
    } else if (p2Choice == 3) {
        // Blue Men
        BlueMen p2;
        setPlayer2(p2);
    } else if (p2Choice == 4) {
        // Medusa
        Medusa p2;
        setPlayer2(p2);
    } else if (p2Choice == 5) {
        // Harry Potter
        HarryPotter p2;
        setPlayer2(p2);
    }
    startGame();
}


Game::Game(Character &player1, Character &player2) {
    setPlayer1(player1);
    setPlayer2(player2);
    startGame();
}

/****************************************************
** DESTRUCTORS
****************************************************/

Game::~Game() {

}

/****************************************************
** GETTERS / SETTERS
****************************************************/

void Game::setPlayer1(Character &player) {
    player1 = &player;
}

void Game::setPlayer2(Character &player) {
    player2 = &player;
}

Character* Game::getPlayer1() {
    return player1;
}

Character* Game::getPlayer2() {
    return player2;
}

/****************************************************
** Description: starts the game
****************************************************/

void Game::startGame() {
    round = 0;
    runRound();
}

/****************************************************
** Description: runs a round
****************************************************/

void Game::runRound() {
    // Increment the round
    round++;

    // Print a separator
    cout << "-------------------------------------------" << endl;

    // Print what round it is
    cout << "Round " << round << endl << endl;

    // Start with player 1's attack
    cout << "Player 1 attacks!" << endl;
    runAttack(player1, player2);

    // Then let player 2 attack
    cout << "Player 2 attacks!" << endl;
    runAttack(player2, player1);

    // Print a separator
    cout << "-------------------------------------------" << endl;
}

/****************************************************
** Description: runs an attack, takes pointers to
** the attacker and defender. these should be
** player 1 or player 2 respectively.
****************************************************/

void Game::runAttack(Character* attacker, Character* defender) {
    // Make a vector for attack dice
    vector<Die*> attackDice;
    int attackTotal = 0;
    int currentRoll = 0;
    int numAttackDice = attacker->getAttack().numDice;
    int numAttackDiceSides = attacker->getAttack().numDiceSides;
    for (int i = 0; i < numAttackDice; i++) {
        attackDice.push_back(new Die(numAttackDiceSides));
        currentRoll = attackDice[i]->roll();
        attackTotal += currentRoll;
        cout << "Added attackDie[" << i << "]: " << attackDice[i] << endl;
        cout << "Current roll: " << currentRoll << endl;
        cout << "Attack total: " << attackTotal << endl;
    }

    // Print out the attack
    cout << "Attacker type: " << attacker->getName() << endl;
    cout << "Defender type: " << defender->getName() << ", Armor: " << defender->getArmor() << ", Strength: " << defender->getStrength() << endl;
    cout << attacker->getName() << "'s attack dice roll: " << "TODO" << endl;
    cout << defender->getName() << "'s defense dice roll: " << "TODO" << endl;
    cout << "Total inflicted damage: " << "TODO" << endl;
    cout << defender->getName() << "'s new strength: " << defender->getStrength() << endl;
    cout << endl;
}

/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/

#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;

/****************************************************
** CONSTRUCTORS
****************************************************/

Game::Game() {
    // Default constructor prompts user to select characters
    int p1Choice = 0, p2Choice = 0;
    vector<string> charMenuItems = {"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
    Menu charMenu(charMenuItems);
    // Prompt for player 1
    charMenu.setPromptText("Select a character for player 1");
    p1Choice = charMenu.showMenu();
    // Create player1
    Character* p1;
    if (p1Choice == 1) {
        // Vampire
        p1 = new Vampire;
    } else if (p1Choice == 2) {
        // Barbarian
        p1 = new Barbarian;
    } else if (p1Choice == 3) {
        // Blue Men
        p1 = new BlueMen;
    } else if (p1Choice == 4) {
        // Medusa
        p1 = new Medusa;
    } else if (p1Choice == 5) {
        // Harry Potter
        p1 = new HarryPotter;
    }
    setPlayer1(p1);
    // Prompt for player 2
    charMenu.setPromptText("Select a character for player 2");
    p2Choice = charMenu.showMenu();
    // Create player2
    Character* p2;
    if (p2Choice == 1) {
        // Vampire
        p2 = new Vampire;
    } else if (p2Choice == 2) {
        // Barbarian
        p2 = new Barbarian;
    } else if (p2Choice == 3) {
        // Blue Men
        p2 = new BlueMen;
    } else if (p2Choice == 4) {
        // Medusa
        p2 = new Medusa;
    } else if (p2Choice == 5) {
        // Harry Potter
        p2 = new HarryPotter;
    }
    setPlayer2(p2);
    // Start the game
    startGame();
}

/****************************************************
** DESTRUCTORS
****************************************************/

Game::~Game() {
    // Delete the dynamically allocated players
    delete player1;
    delete player2;
}

/****************************************************
** GETTERS / SETTERS
****************************************************/

void Game::setPlayer1(Character *player) {
    player1 = player;
}

void Game::setPlayer2(Character *player) {
    player2 = player;
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
    // Initialize the round number to 0
    round = 0;
    // Initialize a flag to know if the game should keep going.
    bool everyoneAlive = true;
    // Clear cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
    do {
        if (round > 0) {
            // Pause between rounds
            string tmp;
            cout << "Press enter to run a new round" << endl;
            getline(cin, tmp);
        }
        // Run the round
        everyoneAlive = runRound();
    } while (everyoneAlive);
}

/****************************************************
** Description: runs a round. Returns true if the
** game should continue (no one has died).
****************************************************/

bool Game::runRound() {
    bool everyoneAlive = true;

    // Increment the round
    round++;

    // Print a separator
    cout << "-------------------------------------------" << endl;

    // Print what round it is
    cout << "Round " << round << endl << endl;

    // Start with player 1's attack
    cout << "Player 1 attacks! " << endl;

    int attackTotal = player1->attack(player2);
    player2->defend(player1, attackTotal);

    // Check to see if player2 is still alive
    if (player2->isAlive()) {
        // Then let player 2 attack
        cout << "Player 2 attacks!" << endl;

        attackTotal = player2->attack(player1);
        player1->defend(player2, attackTotal);
        // Check to see if player 1 died in the attack
        if (!player1->isAlive()) {
            everyoneAlive = false;
            cout << "Player 1 has died. Game over." << endl;
        }
    } else {
        everyoneAlive = false;
        cout << "Player 2 has died. Game over." << endl;
    }

    // Print a separator
    cout << "-------------------------------------------" << endl << endl;

    return everyoneAlive;
}
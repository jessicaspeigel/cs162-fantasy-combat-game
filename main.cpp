/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 Project 3
** Date: 02/18/2018
** Description: Fantasy Combat Game main
****************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Menu.hpp"
#include "InputValidation.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Say hi to the user
    cout << "Welcome to the fantasy combat game!" << endl;
    // Get the main menu ready
    vector<string> mainMenuItems = {"Choose characters for combat", "Exit"};
    Menu mainMenu(mainMenuItems);
    int menuChoice = 1;
    // Start the program
    do {
        // Show the menu and get a choice
        menuChoice = mainMenu.showMenu();
        if (menuChoice != 2) {
            // Start a new game
            Game combatGame;

            // Update the menu text once the game has run once
            mainMenuItems[0] = "Play again";
            mainMenuItems[1] = "Exit";
            mainMenu.setMenuItems(mainMenuItems);
        }
    } while (menuChoice != 2); // Choosing 2 equals quit

    return 0;
}
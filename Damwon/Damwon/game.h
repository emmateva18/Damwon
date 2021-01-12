#pragma once
#include <iostream>
#include <time.h>
#include <iomanip> 
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "structures.h"

using namespace std;

//==================================================================\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==================================================================//

//Checks if the coordinates include duplicates, chars out of the range or spaces
bool checkCoordinates(string coordinates, char min, char max, int size, bool duplicates);

//Forces you to enter a number not string
void checkForWrongInput(int& variable);

//Generates four random numbers
void generateRandomNumbers(int* numbers);

//Forces you to enter string but displays it like a password with "*"
void asteriskInput(string& coordinates);

//==========================================================================\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==========================================================================//

//Gives color to the console 
void color(int color);

//Displays the guessed numbers in an understandable way
void guessDisplay(int guessedNumAndPos, int guessedNum, int guessedNumAndPosMax, string guess);

//Forces you to write proper coordinates with asterisk input
void userInputCoordinates(string& coordinates);

//Displays the warnings why your data is not accepted
void displayWarnings(int error1, int error2, int error3, int error4, char min, char max, int size);

//Forces you to write proper coordinates with asterisk input
void customGameValidation(int& variable, int min, int max);

//Displays the header of the game
void headerGameInterface(int guessedNumAndPos, int guessedNum, vector<GUESS> guesses, int playerID);

//Displays the interface of the game
void gameInterface(vector<GUESS> guesses, int tries, int guessedNumAndPosMax, int guessedNumMax, int playerID);

//The function forces you to type your own settings with which you want to play the game and then you need to guess the coordinates
void customMode();

//Play the game (guess the coordinates)
void defaultMode(int choice);

//Displays the menu
void showMenu();

//Main menu
bool menu();

//Main function which starts the main menu
void game();
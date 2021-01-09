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

bool checkCoordinates(string coordinates, char min, char max, int size, bool duplicates);

void checkForWrongInput(int& variable);

void generateRandomNumbers(int* numbers);

void asteriskInput(string& coordinates);

//==========================================================================\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==========================================================================//

void color(int color);

void guessDisplay(int guessedNumAndPos, int guessedNum, int guessedNumAndPosMax, string guess);

void userInputCoordinates(string& coordinates);

void displayWarnings(int error1, int error2, int error3, int error4, char min, char max, int size);

void customGameValidation(int& variable, int min, int max); ////

void headerGameInterface(int guessedNumAndPos, int guessedNum, vector<GUESS> guesses, int playerID);

void gameInterface(vector<GUESS> guesses, int tries, int guessedNumAndPosMax, int guessedNumMax, int playerID);

void customMode();

void defaultMode(int choice);

void showMenu();

bool menu();

void game();
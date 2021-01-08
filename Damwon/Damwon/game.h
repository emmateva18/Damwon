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
#include "game.h"

using namespace std;

void color(int color);

void checkForWrongInput(int& variable);

void asteriskInput(string& coordinates);

void guessInput(string& coordinates);

void guessDisplay(int guessedNumAndPos, int guessedNum, string guess);

void generateRandomNumbers(int* numbers);

void displayWarnings(int error1, int error2, int error3, char min, char max, int size);

bool checkCoordinates(string coordinates, char min, char max, int size, bool duplicates);

void userInputCoordinates(string& coordinates);

void customGameValidation(int& variable, int min, int max);

void gameInterface(vector<GUESS> guesses, int tries, int numbers, int playerID);

void customMode();

void guesses(string coordinates);

void menu();

void game();
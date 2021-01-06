#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void checkForWrongInput(int& variable);

void generateRandomNumbers(int* numbers);

void checkCoordinates(int& errors, string coordinates);

void userInputCoordinates(string& coordinates);

void menu(int* numbers, string& coordinates);

void game();
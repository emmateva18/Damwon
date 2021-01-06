#pragma once
#include <iostream>
#include <time.h>
#include <iomanip> 
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include <Windows.h>
using namespace std;

void circle(int mainColor, int count);

void checkForWrongInput(int& variable);

void generateRandomNumbers(int* numbers);

void checkCoordinates(int& errors, string coordinates);

void userInputCoordinates(string& coordinates);

void menu(int* numbers, string& coordinates);

void game();
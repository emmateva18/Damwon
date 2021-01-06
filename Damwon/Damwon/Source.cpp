#include "game.h"

void checkForWrongInput(int& variable) 
{
	while (cin.fail())
	{
		cout << "Enter a number, please!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> variable;
	}
}
void generateRandomNumbers(int* numbers)
{
	srand(time(NULL));
	numbers[0] = rand() % 8;
	do
	{
		numbers[1] = rand() % 8;
	} while (numbers[0] == numbers[1]);
	do
	{
		numbers[2] = rand() % 8;
	} while (numbers[2] == numbers[0] or numbers[2] == numbers[1]);
	do
	{
		numbers[3] = rand() % 8;
	} while (numbers[3] == numbers[0] or numbers[3] == numbers[1] or numbers[3] == numbers[2]);
}
void checkCoordinates(int& errors, string coordinates)
{
	for (size_t i = 0; i < coordinates.length(); i++)
	{
		if (coordinates[i] < '0' or coordinates[i]> '7')
		{
			errors++;
		}
	}
	for (size_t i = 0; i < coordinates.length(); i++)
	{
		for (size_t j = 0; j < coordinates.length(); j++)
		{
			if (coordinates[i] == coordinates[j] and i != j)
			{
				errors++;
			}
		}
	}
	if (coordinates.size() < 4)
	{
		errors++;
	}
}
void userInputCoordinates(string& coordinates)
{
	int errors = 0;
	cout << "Enter coordinates: ";
	cin >> coordinates;
	checkCoordinates(errors, coordinates);
	while (errors > 0)
	{
		cout << "Your coordinates can include only numbers from 0 to 7\n";
		errors = 0;
		cout << "Enter new coordinates: ";
		cin >> coordinates;
		checkCoordinates(errors, coordinates);
	}
}
void menu(int* numbers, string& coordinates)
{
	int choice;
	stringstream ss;
	cout << "Welcome to the game!" << endl;
	cout << "1. Singleplayer" << endl;
	cout << "2. Multiplayer" << endl;
	cin >> choice;
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1:
		generateRandomNumbers(numbers);
		ss << numbers[0] << numbers[1] << numbers[2] << numbers[3];
		coordinates = ss.str();
		break;
	case 2:
		userInputCoordinates(coordinates);
		break;
	default: cout << "Invalid choice!";
		menu(numbers,coordinates);
	}
}
void guesses(string coordinates)
{
	int guessedNumberAndPos = 0;
	int guessedNumbers = 0;
	int tries = 0;
	int errors = 0;
	string guess;
	bool win = 0;
	while (win != 1 and tries != 13) {
		guessedNumberAndPos = 0;
		guessedNumbers = 0;
		int guessed[4] = { 8,8,8,8 };
		cout << "\nMake a guess\n" << endl;
		cout << "You have to enter 4 different numbers without any spaces from 0 to 7!\n";
		cin >> guess;
		checkCoordinates(errors, guess);
		while (errors > 0)
		{
			cout << "\nInvalid coordinates";
			errors = 0;
			cout << "\nEnter new 4 different numbers without any spaces from 0 to 7!\n";
			cin >> guess;
			checkCoordinates(errors, guess);
		}
		for (int i = 0; i < coordinates.length(); i++) {
			if (guess[i] == coordinates[i]) {
				guessed[guessedNumberAndPos++] = guess[i];
			}
		}
		for (int i = 0; i < coordinates.length(); i++)
		{
			for (int j = 0; j < coordinates.length(); j++)
			{
				if (guess[i] == guessed[j])
				{
					i++;
					j = 0;
				}
				else if (guess[i] == coordinates[j])
				{
					guessedNumbers++;
				}
			}
		}
		cout << "Guessed numbers and positions " << guessedNumberAndPos << endl << "Guessed numbers: " << guessedNumbers << endl;
		if (guessedNumberAndPos == 4)
		{
			win = 1;
			cout << "\nCongrats!\nYou guessed the coordinates!";
		}
		else
		{
			tries++;
			if (tries == 13)
			{
				cout << "\nYou lost!\nThe coordinates were:" << coordinates;
			}
			else
			{
				cout << "\nYou have " << 13 - tries << " tries remaining";
			}
		}
	}
}
void game()
{
	int numbers[4];
	string coordinates;
	menu(numbers, coordinates);
	srand(time(NULL));
	guesses(coordinates);
}
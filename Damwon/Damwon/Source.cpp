#include "game.h"
#include "structures.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void color(int color)
{
	SetConsoleTextAttribute(console, color);
}

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
void asteriskInput(string& coordinates)
{
	char number;
	number = _getch();
	while (number != 13)
	{
		if (number == 8)
		{
			if (coordinates.length() > 0)
			{
				cout << "\b \b";
				coordinates.erase(coordinates.length() - 1);
			}
		}
		else
		{
			cout << "*";
			coordinates += number;
		}
		number = _getch();
	}
}
void guessInput(string& coordinates)
{
	char number;
	number = _getch();
	while (number != 13)
	{
		if (number == 8)
		{
			if (coordinates.length() > 0)
			{
				cout << "\b \b";
				coordinates.erase(coordinates.length() - 1);
			}
		}
		else
		{
			coordinates += number;
		}
		number = _getch();
	}
}
void circle(int mainColor, int count, int space = 0)
{

}
void guessDisplay(int guessedNumAndPos, int guessedNum, string guess) //10 12
{
	int count = guessedNum + guessedNumAndPos;
	cout << "     Guessed numbers and positions";
	if (count > 4)
	{
		for (int i = 0; i < (count - 4) * 10; i++)
		{
			cout << " ";
		}
	}
	cout << "               Player's guesses";
	if (count > 4)
	{
		for (int i = 0; i < (count - 4) * 10; i++)
		{
			cout << " ";
		}
	}
	cout<<"               Guessed numbers" << endl; 
	color(10);
	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);
			for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
			{
				cout << " ";
			}
		}
		cout << "  *****   ";
	}
	cout << endl;
	color(10);
	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);
			for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
			{
				cout << " ";
			}
		}
		cout << " *******  ";
	}
	color(10);
	cout << endl;
	for (int i = 0; i < guessedNumAndPos; i++)
	{
		cout << "********* ";
	}
	color(12);
	color(12);
	if (guessedNumAndPos <= 4)
	for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 15 - (guess.size() - 4) / 2; j++)
	{
		cout << " ";
	}
	cout << guess;
	for (int i = 0; i < 13 - guess.size(); i++)
	{
		cout << " ";
	}
	for (int i = 0; i < guessedNum; i++)
	{
		cout << "********* ";
	}
	color(10);
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);
			for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
			{
				cout << " ";
			}
		}
		cout << " *******  ";
	}
	color(10);
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);
			for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
			{
				cout << " ";
			}
		}
		cout << "  *****   ";
	}
	cout << endl;
	color(7);

}
void generateRandomNumbers(int* numbers)
{
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
void checkCoordinates(int& errors, string coordinates, char min, char max, int size,bool duplicates=0)
{
	if (duplicates == 0)
	{
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
	}
	for (size_t i = 0; i < coordinates.length(); i++)
	{
		if (coordinates[i] < min or coordinates[i]> max)
		{
			errors++;
		}
	}
	if (coordinates.size() != size)
	{
		errors++;
	}
}
void userInputCoordinates(string& coordinates)
{
	int errors = 0;
	cout << "Enter coordinates: ";
	asteriskInput(coordinates);
	checkCoordinates(errors, coordinates, '0', '7', 4);
	while (errors > 0)
	{
		cout << "\nYour coordinates can include only numbers from 0 to 7 and it should consist of four numbers!\n";
		errors = 0;
		cout << "Enter new coordinates: ";
		coordinates = "";
		asteriskInput(coordinates);
		checkCoordinates(errors, coordinates, '0', '7', 4);
	}
}
void customGameValidation(int& variable, int min, int max)
{
	cin >> variable;
	checkForWrongInput(variable);
	while (variable > max or variable < min)
	{
		cout << "\nSomething went wrong! Try again: ";
		cin >> variable;
		checkForWrongInput(variable);
	}
}
void gameInterface(vector<GUESS> guesses, int tries, int numbers, int playerID = 0)
{
	system("cls");
	if (playerID > 0)
	{
		cout << "Player " << playerID << endl;
	}
	for (size_t i = 0; i < guesses.size(); i++)
	{
		guessDisplay(guesses[i].guessedPosAndNum, guesses[i].guessedNum, guesses[i].guess);
	}
	cout << endl;
	cout << setw(105) << "Tries remaining:" << tries << endl;
}
void customMode()
{
	int players;
	int N;
	int tries;
	int choice;
	int range;
	int numbers[10];
	int guessedNumberAndPos = 0;
	int guessedNumbers = 0;
	int errors = 0;
	bool duplicates = 0;
	string guess;
	vector<string> coordinates;
	vector<GUESS> guesses;
	GUESS temp;
	PLAYER temp2;
	vector<PLAYER> player;
	cout << "Enter how many players are you | from 1 to 4: ";
	customGameValidation(players, 1, 4);
	cout << "Enter how many numbers your coordinates will consist of | from 4 to 10: ";
	customGameValidation(N, 4, 10);
	cout << "Numbers that can be included are from 0 to (4/5/6/7/8/9): ";
	customGameValidation(range, 4, 9);
	cout << "\nEnter how many tries each player has | from 1 to 100: ";
	customGameValidation(tries, 1, 100);
	if (range+1 >= N)
	{
		cout << "Do you want duplicates in the numbers?\n1. Yes\n2. No\nYour choice: ";
		cin >> choice;
		checkForWrongInput(choice);
		int i = 0;
		int j = 0;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < N; i++)
			{
				numbers[i] = rand() % (range + 1);
			}
			duplicates = 1;
			break;
		case 2:
			for (int k = 0; k < players; k++)
			{
				do
				{
					j = 0;
					numbers[i] = rand() % (range + 1);
					while (j < i)
					{
						if (numbers[i] != numbers[j])
						{
							j++;
						}
						else
						{
							j = 0;
							numbers[i] = rand() % (range + 1);
						}
					}
					i++;
				} while (i < N);
			}
			break;
		default: cout << "Invalid option!\nPlease try again: ";
			cin >> choice;
			checkForWrongInput(choice);
			break;
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			numbers[i] = rand() % (range + 1);
		}
		duplicates = 1;
	}
	stringstream ss;
	for (int i = 0; i < N; i++)
	{
		ss << numbers[i];
	}
	coordinates.push_back(ss.str());
	temp2.tries = tries;
	
	bool win;
	int guessed[10];
	for (int k = 0; k < players; k++)
	{
		guessed[10] = { 11 };
		temp2.coordinates = coordinates[k];
		player.push_back(temp2);
		win = 0;
		cout << "\nMake a guess\n" << endl;
		cout << "You have to enter " << N << " numbers without any spaces from 0 to " << range << "!\n";
		while (win != 1 and player[k].tries != 0) {
			guessedNumberAndPos = 0;
			guessedNumbers = 0;
			cout << "Enter coordinates: ";
			cin >> guess;
			checkCoordinates(errors, guess, '0', char(range) + '0', N,duplicates);
			while (errors > 0)
			{
				cout << "\nInvalid coordinates";
				errors = 0;
				cout << "\nEnter new " << N << " numbers without any spaces from 0 to " << range << ": ";
				cin >> guess;
				checkCoordinates(errors, guess, '0', char(range) + '0', N, duplicates);
			}
			for (size_t i = 0; i < coordinates[k].length(); i++) {
				if (guess[i] == coordinates[k][i]) {
					guessed[guessedNumberAndPos++] = guess[i];
				}
			}
			for (size_t i = 0; i < coordinates[k].length(); i++)
			{
				for (int j = 0; j < coordinates[k].length(); j++)
				{
					if (guess[i] == guessed[j])
					{
						i++;
						j = -1;
					}
					else if (guess[i] == coordinates[k][j])
					{
						guessedNumbers++;
					}
				}
			}
			temp.guessedPosAndNum = guessedNumberAndPos;
			temp.guessedNum = guessedNumbers;
			temp.guess = guess;
			guesses.push_back(temp);
			player[k].tries--;
			gameInterface(guesses, player[k].tries, N, k+1);
			if (guessedNumberAndPos == 4)
			{
				win = 1;
				cout << "\nCongrats!\nYou guessed the coordinates!";
			}
			else
			{
				if (player[k].tries == 0)
				{
					cout << "\nYou lost!\nYour coordinates were:" << coordinates[k];
				}
			}
		}
	}
	int max = 0;
	for (int i = 0; i < players; i++)
	{
		if (player[i].tries > max)
		{
			max = player[i].tries;
		}
	}
	if (max == 0)
	{
		cout << "There is no winner!";
	}
	for (int i = 0; i < players; i++)
	{
		cout << "\nThe winner/s is/are:\n";
		if (player[i].tries == max)
		{
			cout << "Player " << i << endl;
		}
	}
}
void guesses(string coordinates)
{
	int guessedNumberAndPos = 0;
	int guessedNumbers = 0;
	int tries = 13;
	int errors = 0;
	string guess;
	GUESS temp;
	vector<GUESS> guesses;
	bool win = 0;
	cout << "\nMake a guess\n" << endl;
	cout << "You have to enter 4 different numbers without any spaces from 0 to 7!\n";
	while (win != 1 and tries != 0) {
		guessedNumberAndPos = 0;
		guessedNumbers = 0;
		int guessed[4] = { 8,8,8,8 };
		cout << "Enter coordinates: ";
		cin >> guess;
		checkCoordinates(errors, guess, '0', '7', 4);
		while (errors > 0)
		{
			cout << "\nInvalid coordinates";
			errors = 0;
			cout << "\nEnter new 4 different numbers without any spaces from 0 to 7: ";
			cin >> guess;
			checkCoordinates(errors, guess, '0', '7', 4);
		}
		for (size_t i = 0; i < coordinates.length(); i++) {
			if (guess[i] == coordinates[i]) {
				guessed[guessedNumberAndPos++] = guess[i];
			}
		}
		for (size_t i = 0; i < coordinates.length(); i++)
		{
			for (int j = 0; j < coordinates.length(); j++)
			{
				if (guess[i] == guessed[j])
				{
					i++;
					j = -1;
				}
				else if (guess[i] == coordinates[j])
				{
					guessedNumbers++;
				}
			}
		}
		temp.guessedPosAndNum = guessedNumberAndPos;
		temp.guessedNum = guessedNumbers;
		temp.guess = guess;
		tries--;
		guesses.push_back(temp);
		gameInterface(guesses, tries,4);
		if (guessedNumberAndPos == 4)
		{
			win = 1;
			cout << "\nCongrats!\nYou guessed the coordinates!";
		}
		else
		{
			if (tries == 0)
			{
				cout << "\nYou lost!\nThe coordinates were:" << coordinates;
			}
		}
	}
}

void menu(int* numbers, string& coordinates)
{
	int choice;
	stringstream ss;
	cout << "\nWelcome to the game!" << endl;
	cout << "1. Singleplayer" << endl;
	cout << "2. Multiplayer" << endl;
	cout << "3. Custom mode" << endl;
	cin >> choice;
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1:
		generateRandomNumbers(numbers);
		ss << numbers[0] << numbers[1] << numbers[2] << numbers[3];
		coordinates = ss.str();
		guesses(coordinates);
		break;
	case 2:
		userInputCoordinates(coordinates);
		guesses(coordinates);
		break;
	case 3: customMode();
		break;
	default: cout << "Invalid choice!";
		menu(numbers, coordinates);
	}
}

void game()
{
	int numbers[4];
	string coordinates;
	menu(numbers, coordinates);
	srand(time(NULL));
}
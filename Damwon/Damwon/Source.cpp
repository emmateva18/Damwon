#include "game.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//==================================================================\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==================================================================//

//Checks if the coordinates include duplicates, chars out of the range or spaces
bool checkCoordinates(string coordinates, char min, char max, int size, bool duplicates = 0)
{
	bool error1 = 0; //Duplicates
	bool error2 = 0; //Chars out of the possible range
	bool error3 = 0; //More or less numbers than needed
	bool error4 = 0; //Contains spaces

	if (duplicates == 0)
	{
		for (size_t i = 0; i < coordinates.length(); i++)
		{
			for (size_t j = 0; j < coordinates.length(); j++)
			{
				if (coordinates[i] == coordinates[j] and i != j)
				{
					error1 = true;
				}
			}
		}
	}

	for (size_t i = 0; i < coordinates.length(); i++)
	{
		if (coordinates[i] < min or coordinates[i]> max)
		{
			error2 = true;
		}
	}

	if (coordinates.size() != size)
	{
		error3 = true;
	}

	if (coordinates.find(' ') != string::npos)
	{
		error4 = true;
	}

	displayWarnings(error1, error2, error3, error4, min, max, size);

	if (error1 or error2 or error3 or error4)
	{
		return true;
	}

	return false;
}

//Forces you to enter a number not string
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

//Generates four random numbers
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

//Forces you to enter string but displays it like a password with "*"
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

//==========================================================================\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==========================================================================//

//Gives color to the console 
void color(int color)
{
	SetConsoleTextAttribute(console, color);
}

//Displays the guessed numbers in an understandable way
void guessDisplay(int guessedNumAndPos, int guessedNum, int guessedNumAndPosMax, string guess)
{
	int count = guessedNum + guessedNumAndPos;

	color(10);

	//First line

	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);
			if (guessedNumAndPosMax < 4) //Displays spaces if there are less than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";

				}
			}
			else //Displays spaces if there are more than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (guessedNumAndPosMax - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";
				}
			}
		}

		cout << "  *****   ";
	}

	cout << endl;
	color(10);

	//Second line

	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);

			if (guessedNumAndPosMax < 4) //Displays spaces if there are less than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";
				}
			}
			else //Displays spaces if there are more than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (guessedNumAndPosMax - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";
				}
			}
		}

		cout << " *******  ";
	}

	color(10);

	cout << endl;

	//Third Middle line

	for (int i = 0; i < guessedNumAndPos; i++)
	{
		cout << "********* ";
	}

	color(12);

	if (guessedNumAndPosMax < 4) //Displays spaces if there are less than 4 guessed numbers with guessed position
	{
		for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 15 - (guess.size() - 4) / 2; j++)
		{
			cout << " ";
		}
	}
	else //Displays spaces if there are more than 4 guessed numbers with guessed position
	{

		for (int j = 0; j < (guessedNumAndPosMax - guessedNumAndPos) * 10 + 15 - (guess.size() - 4) / 2; j++)
		{
			cout << " ";
		}
	}

	cout << guess;  //Displays the guess

	for (int i = 0; i < 11 - guess.size() / 2; i++)
	{
		cout << " ";
	}

	if (guess.size() % 2 == 1)
	{
		cout << "\b \b";
	}

	for (int i = 0; i < guessedNum; i++)
	{
		cout << "********* ";
	}

	color(10);

	cout << endl;

	//Fourth line

	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);

			if (guessedNumAndPosMax < 4) //Displays spaces if there are less than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";

				}
			}
			else //Displays spaces if there are more than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (guessedNumAndPosMax - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";
				}
			}
		}

		cout << " *******  ";
	}

	color(10);

	cout << endl;

	//Fifth line

	for (int i = 0; i < count; i++)
	{
		if (i == guessedNumAndPos)
		{
			color(12);

			if (guessedNumAndPosMax < 4) //Displays spaces if there are less than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (4 - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";
				}
			}
			else //Displays spaces if there are more than 4 guessed numbers with guessed position
			{
				for (int j = 0; j < (guessedNumAndPosMax - guessedNumAndPos) * 10 + 28; j++)
				{
					cout << " ";
				}
			}
		}

		cout << "  *****   ";
	}

	cout << endl << endl;

	color(14);
}

//Forces you to write proper coordinates with asterisk input
void userInputCoordinates(string& coordinates)
{
	cout << "Enter coordinates: ";
	asteriskInput(coordinates);

	while (checkCoordinates(coordinates, '0', '7', 4))
	{
		cout << "Enter new coordinates: ";
		coordinates = "";
		asteriskInput(coordinates);
	}
}

//Displays the warnings why your data is not accepted
void displayWarnings(int error1, int error2, int error3, int error4, char min, char max, int size)
{
	color(12);
	if (error1) //Duplicates
	{
		cout << "\nYour coordinates include duplicates (same numbers)!\n";
	}
	if (error2) //Chars out of the possible range
	{
		cout << "\nYour coordinates can include only numbers from " << int(min - '0') << " to " << int(max - '0') << "!\n";
	}
	if (error3) //More or less numbers than needed
	{
		cout << "\nYour coordinates include more or less numbers than needed! (" << size << ")" << endl;
	}
	if (error4) //Contains spaces
	{
		cout << "\nYour coordinates include spaces!" << endl;
	}
	color(14);
}

//Forces you to write proper coordinates with asterisk input
void customGameValidation(int& variable, int min, int max)
{
	cin >> variable;
	checkForWrongInput(variable);

	while (variable > max or variable < min)
	{
		cout << "\nEnter a number in the valid range: ";
		cin >> variable;
		checkForWrongInput(variable);
	}
}

//Displays the header of the game
void headerGameInterface(int guessedNumAndPos, int guessedNum, vector<GUESS> guesses, int playerID = 0)
{
	if (playerID > 0) //If the mode is custom mode it will display the ID of the player
	{
		cout << "Player " << playerID << endl;
	}

	if (guessedNumAndPos > 4) //If there are more than 4 guessed numbers and position it will display spaces so the header stays in its place
	{
		for (int i = 0; i < (guessedNumAndPos - 4) * 5; i++)
		{
			cout << " ";
		}
	}

	cout << "     Guessed numbers and positions";

	if (guessedNumAndPos > 4) //If there are more than 4 guessed numbers and position it will display spaces so the header stays in its place
	{
		for (int i = 0; i < (guessedNumAndPos - 4) * 5; i++)
		{
			cout << " ";
		}
	}

	cout << "               Player's guesses";

	if (guessedNum > 4) //If there are more than 4 guessed numbers it will display spaces so the header stays in its place
	{
		for (int i = 0; i < (guessedNum - 4) * 5; i++)
		{
			cout << " ";
		}
	}

	cout << "               Guessed numbers" << endl;
}

//Displays the interface of the game
void gameInterface(vector<GUESS> guesses, int tries, int guessedNumAndPosMax, int guessedNumMax, int playerID = 0)
{
	system("cls");

	headerGameInterface(guessedNumAndPosMax, guessedNumMax, guesses, playerID); //Displays the header

	for (size_t i = 0; i < guesses.size(); i++)
	{
		guessDisplay(guesses[i].guessedPosAndNum, guesses[i].guessedNum, guessedNumAndPosMax, guesses[i].guess); //Displays each try with its guessed numbers and positions
	}

	cout << endl << setw(105) << "Tries remaining:" << tries << endl; //Displays how many tries you have left
}

//The function forces you to type your own settings with which you want to play the game and then you need to guess the coordinates
void customMode()
{
	int playersCount;
	int numbersCount;
	int tries;
	int choice;
	int possibleRange;
	int guessedNumbersAndPos = 0;
	int guessedNumbersAndPosMax = 0;
	int guessedNumbersMax = 0;
	int guessedNumbers = 0;
	int max = 0;
	int i = 0;
	int j = 0;
	int numbers[10];

	bool win;
	bool duplicates = 0;

	string guess;
	string playerCoordinates;

	stringstream ss;

	GUESS temporaryGuess;

	PLAYER temporaryPlayer;

	vector<string> coordinates;
	vector<GUESS> guesses;
	vector<PLAYER> players;

	//Enter your own requirements for the game

	cout << "Enter how many players are you | from 1 to 4: ";
	customGameValidation(playersCount, 1, 4);
	cout << "Enter how many numbers your coordinates will consist of | from 4 to 10: ";
	customGameValidation(numbersCount, 4, 10);
	cout << "Numbers that can be included are from 0 to (4/5/6/7/8/9): ";
	customGameValidation(possibleRange, 4, 9);
	cout << "\nEnter how many tries each player has | from 1 to 100: ";
	customGameValidation(tries, 1, 100);

	if (possibleRange >= numbersCount - 1) //If it is possible to create coordinates without any duplicates it asks you if you want duplicates
	{
		i = 0;
		j = 0;
		cout << "Do you want duplicated numbers?\n1. Yes\n2. No\nYour choice: ";
		cin >> choice;
		checkForWrongInput(choice);
		switch (choice)
		{
		case 1:
			for (int k = 0; k < playersCount; k++)
			{
				for (int i = 0; i < numbersCount; i++)
				{
					numbers[i] = rand() % (possibleRange + 1);
				}
				ss.str("");
				for (int i = 0; i < numbersCount; i++)
				{
					ss << numbers[i];
				}
				coordinates.push_back(ss.str());
			}
			duplicates = 1;
			break;
		case 2:
			for (int k = 0; k < playersCount; k++)
			{
				i = 0;
				do
				{
					j = 0;
					numbers[i] = rand() % (possibleRange + 1);
					while (j < i)
					{
						if (numbers[i] != numbers[j])
						{
							j++;
						}
						else
						{
							j = 0;
							numbers[i] = rand() % (possibleRange + 1);
						}
					}
					i++;
				} while (i < numbersCount);

				ss.str("");

				for (int i = 0; i < numbersCount; i++)
				{
					ss << numbers[i];
				}

				coordinates.push_back(ss.str());

			}
			break;

		default:
			cout << "Invalid option!\nPlease try again: ";
			cin >> choice;
			checkForWrongInput(choice);
			break;
		}
	}
	else
	{
		for (int k = 0; k < playersCount; k++)
		{
			for (int i = 0; i < numbersCount; i++)
			{
				numbers[i] = rand() % (possibleRange + 1);
			}

			ss.str("");
			for (int i = 0; i < numbersCount; i++)
			{
				ss << numbers[i];
			}

			coordinates.push_back(ss.str());
		}
		duplicates = 1;
	}

	temporaryPlayer.tries = tries;

	cin.ignore();

	for (int k = 0; k < playersCount; k++)
	{
		win = 0;
		guesses.clear();
		players.push_back(temporaryPlayer);

		system("cls");
		cout << "\nMake a guess\n" << endl;
		cout << "You have to enter " << numbersCount << " numbers without any spaces from 0 to " << possibleRange << "!\n";

		while (win == 0 and players[k].tries != 0)
		{
			guessedNumbersAndPos = 0;
			guessedNumbers = 0;

			cout << "Enter coordinates: ";
			getline(cin, guess);

			while (checkCoordinates(guess, '0', char(possibleRange) + '0', numbersCount, duplicates))
			{
				cout << "\nEnter new coordinates: ";
				getline(cin, guess);
			}

			playerCoordinates = coordinates[k];

			for (size_t i = 0; i < playerCoordinates.length(); i++) //Calculates the guessed numbers with guessed positions
			{
				if (guess[i] == coordinates[k][i])
				{
					guessedNumbersAndPos++;
				}
			}

			for (size_t i = 0; i < guess.size(); i++)
			{
				for (size_t j = 0; j < playerCoordinates.length(); j++)
				{
					if (guess[i] == playerCoordinates[j])
					{
						guessedNumbers++;
						if (playerCoordinates.find(guess[i]) == playerCoordinates.size() - 1)
						{
							playerCoordinates.erase(playerCoordinates.end() - 1);
						}
						else
						{
							for (int l = playerCoordinates.find(guess[i]); l < playerCoordinates.length() - 1; l++)
							{
								playerCoordinates[l] = playerCoordinates[l + 1];
							}

							playerCoordinates.erase(playerCoordinates.end() - 1);

						}

						break;
					}
				}
			} //Calculating both guessed numbers and guessed numbers with guessed positions

			guessedNumbers -= guessedNumbersAndPos; //Substract the guessed numbers with guessed positions to calculate only the guessed numbers without guessed positions

			temporaryGuess.guessedPosAndNum = guessedNumbersAndPos;
			temporaryGuess.guessedNum = guessedNumbers;
			temporaryGuess.guess = guess;

			guesses.push_back(temporaryGuess);

			players[k].tries--;

			for (size_t i = 0; i < guesses.size(); i++)
			{
				if (guesses[i].guessedPosAndNum > guessedNumbersAndPosMax)
				{
					guessedNumbersAndPosMax = guesses[i].guessedPosAndNum;
				}
				if (guesses[i].guessedNum > guessedNumbersMax)
				{
					guessedNumbersMax = guesses[i].guessedNum;
				}
			}

			gameInterface(guesses, players[k].tries, guessedNumbersAndPosMax, guessedNumbersMax, k + 1);

			if (guess == coordinates[k])
			{
				win = 1;
			}
		}
	}

	for (int i = 0; i < playersCount; i++)
	{
		if (players[i].tries > max)
		{
			max = players[i].tries;
		}
	}

	system("cls");

	for (int i = 0; i < playersCount; i++) //Displays the left tries as score of each player
	{
		cout << "\n\nPlayer " << i + 1 << "\nCoordinates: " << coordinates[i] << "\nScore: " << players[i].tries + 1;
	}

	if (max == 0)
	{
		cout << "\nThere is no winner!";
	}

	else
	{
		cout << "\n\nThe winners:\n";

		for (int i = 0; i < playersCount; i++)
		{
			if (players[i].tries == max)
			{
				cout << "Player " << i + 1 << endl;
			}
		}
	}
}

//Play the game (guess the coordinates)
void defaultMode(int choice)
{
	int guessedNumbersAndPos = 0;
	int guessedNumbersAndPosMax = 0;
	int guessedNumbers = 0;
	int guessedNumbersMax = 0;
	int tries = 13;
	int numbers[4];

	bool win = 0;

	string guess;
	string coordinates;
	stringstream ss;

	GUESS temp;
	vector<GUESS> guesses;

	generateRandomNumbers(numbers);

	if (choice == 1)
	{
		ss << numbers[0] << numbers[1] << numbers[2] << numbers[3];
		coordinates = ss.str();
	}
	else
	{
		userInputCoordinates(coordinates);
	}

	cin.ignore();
	cout << "\nMake a guess\n" << endl;
	cout << "You have to enter 4 different numbers without any spaces from 0 to 7!\n";

	while (win != 1 and tries != 0)
	{
		guessedNumbersAndPos = 0;
		guessedNumbers = 0;

		cout << "Enter coordinates: ";
		getline(cin, guess);

		while (checkCoordinates(guess, '0', '7', 4))
		{
			cout << "\nEnter new coordinates: ";
			getline(cin, guess);
		}

		for (size_t i = 0; i < coordinates.length(); i++)  //Calculates the guessed numbers with guessed positions
		{
			if (guess[i] == coordinates[i])
			{
				guessedNumbersAndPos++;
			}
		}

		for (size_t i = 0; i < coordinates.length(); i++) //Calculates both guessed numbers and guessed numbers with guessed positions
		{
			for (int j = 0; j < coordinates.length(); j++)
			{
				if (guess[i] == coordinates[j])
				{
					guessedNumbers++;
				}
			}
		}

		guessedNumbers -= guessedNumbersAndPos; //Substract the guessed numbers with guessed positions to calculate only the guessed numbers without guessed positions

		temp.guessedPosAndNum = guessedNumbersAndPos;
		temp.guessedNum = guessedNumbers;
		temp.guess = guess;

		guesses.push_back(temp);

		tries--;

		for (size_t i = 0; i < guesses.size(); i++)
		{
			if (guesses[i].guessedPosAndNum > guessedNumbersAndPosMax)
			{
				guessedNumbersAndPosMax = guesses[i].guessedPosAndNum;
			}
			if (guesses[i].guessedNum > guessedNumbersMax)
			{
				guessedNumbersMax = guesses[i].guessedNum;
			}
		}

		gameInterface(guesses, tries, guessedNumbersAndPosMax, guessedNumbersMax);

		if (guess == coordinates)
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

//Displays the menu
void showMenu()
{
	color(14);
	cout << endl << char(219) << "                        Game                        " << char(219) << endl << char(219);

	for (int i = 0; i < 52; i++)
		cout << char(254);

	cout << char(219) << endl;
	cout << char(219) << "1. Singleplayer     | Guess the coordinates         " << char(219) << endl;
	cout << char(219) << "2. Multiplayer      | Create and guess coordinates  " << char(219) << endl;
	cout << char(219) << "3. Custom mode      | Create your own rules and play" << char(219) << endl;
	cout << char(219) << "9. Exit                                             " << char(219) << endl;
	cout << char(219);

	for (int i = 0; i < 52; i++)
		cout << char(254);

	cout << char(219) << endl;
	cout << char(219) << " Your choice: ";

}

//Main menu
bool menu()
{
	int choice;

	showMenu();

	cin >> choice;
	checkForWrongInput(choice);

	system("cls");
	switch (choice)
	{
	case 1:
		defaultMode(choice);
		break;

	case 2:
		defaultMode(choice);
		break;

	case 3:
		customMode();
		break;

	case 9:
		return false;

	default:
		cout << "Invalid choice!";
		showMenu();
		cin >> choice;
	}

	return true;
}

//Main function which starts the main menu
void game()
{
	bool doMenu = 1;
	while (doMenu)
	{
		doMenu = menu();
	}
}
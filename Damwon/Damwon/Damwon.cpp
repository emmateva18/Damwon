#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
void game()
{
	int guessedNumberAndPos;
	int guessedNumbers;
	int numbers[4];
	int tries = 0;
	string coordinates;
	string guess;
	bool runGame = true;
	bool win;
	cout << "Welcome to the game!" << endl;
	while (runGame == true) {
		guessedNumberAndPos = 0;
		guessedNumbers = 0;
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
		} while (numbers[3] == numbers[0] or numbers[3] == numbers[1] or numbers[3] == numbers[2]);;
		stringstream ss;
		do
		{
			ss << numbers[0] << numbers[1] << numbers[2] << numbers[3];
		} while (numbers[0] == numbers[1] or numbers[0] == numbers[2] or numbers[0] == numbers[3] or numbers[1] == numbers[2] or numbers[1] == numbers[3] or numbers[2] == numbers[3]);
		coordinates = ss.str();
		win = 0;
		while (win == 0 or tries == 13) {
			guessedNumberAndPos = 0;
			guessedNumbers = 0;
			int guessed[4] = { 8,8,8,8 };
			cout << "\nMake a guess" << endl;
			cin >> guess;
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
				runGame = 0;
				cout << "\nCongrats!\nYou guessed the coordinates!";
			}
			else
			{
				tries++;
				if (tries == 13)
				{
					cout << "\nYou lost!\nthe coordinates were:" << coordinates;
					runGame = 0;
				}
				else
				{
					cout << "\nThat was your " << tries << " try!\n" << 13 - tries << " tries remaining";
				}
			}
		}
	}
}
int main() {
	game();
}
#pragma once

using namespace std;

struct GUESS
{
	int guessedPosAndNum=0;
	int guessedNum=0;
	string guess="";
};

struct PLAYER
{
	string coordinates;
	int tries;
};
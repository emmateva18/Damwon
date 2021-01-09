#include "game.h"

void test_ensureNumbersAreUniqe()
{
	int numbers[4];
	bool success = true;

	generateRandomNumbers(numbers);

	if (numbers[0] == numbers[1] || numbers[0] == numbers[2] || numbers[0] == numbers[3] || numbers[1] == numbers[2]
		|| numbers[1] == numbers[3] || numbers[2] == numbers[3])
	{
		success = false;
	}

	cout << success;
}

void test_errorsAccuracy()
{
	// Expected: 0
	// Actual  : 0
	int errors = checkCoordinates("1234", '0', '9', 4, 0);
	cout << (errors == 0) << endl;

	// Expected: 2
	// Actual  : 2
	errors = checkCoordinates("1224", '0', '9', 4, 0);
	cout << (errors == 2) << endl;

	// Expected: 1
	// Actual  : 1
	errors = checkCoordinates("124", '0', '9', 4, 0);
	cout << (errors == 1) << endl;

	// Expected: 3
	// Actual  : 3
	errors = checkCoordinates("114", '0', '9', 4, 0);
	cout << (errors == 2) << endl;

	// Expected: 4
	// Actual  : 4
	errors = checkCoordinates("1234", '5', '9', 4, 0);
	cout << (errors == 4) << endl;
}
/* This is a comment */

#include <iostream>
#include <ctime>

using namespace std;

void PrintIntro(int Diff) {

	cout << "\n\nLEVEL " << Diff;
	cout << "\n\nYou are a secret agent breaking into a super secured data center." << endl;
	cout << "You need to enter the correct codes to continue..." << endl;
	cout << endl;
	cout << endl;

}


bool PlayGame(int Diff) {

	int CodeA = rand() % Diff + Diff;
	int CodeB = rand() % Diff + Diff;
	int CodeC = rand() % Diff + Diff;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	cout << "+ There are 3 numbers in the code..." << endl;
	cout << "+ The codes add-up to " << CodeSum << endl;
	cout << "+ And the codes multiply to give " << CodeProduct << endl;
	cout << endl;

	int GuessA;
	int GuessB;
	int GuessC;

	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (CodeSum == GuessSum && CodeProduct == GuessProduct) {
		cout << "\n \n Damn boi, you're on fire, you've got the file! Let's move on to the next one...";
		cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

		return true;
	}
	else {
		cout << "\n \n Never mind, even legends have the bad days... Keep going!";
		cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

		return false;
	}

}


int main() {

	int LevelDiff = 1;
	const int MaxDiff = 10;

	// Create new random sequence (new seed for rand) based on time of day
	srand(time(NULL)); 

	while (LevelDiff <= MaxDiff) {

		PrintIntro(LevelDiff);

		bool bLevelComplete = PlayGame(LevelDiff);

		cin.clear(); // Clears any errors
		cin.ignore(); // Discards the buffer

		if (bLevelComplete){

			++LevelDiff;

		}

	}

	cout << "*** \n\nYou are a fucking legend, you've done it!! ***";

	return 0;
}

#include <iostream>
#include <ctime>

using namespace std;

void PrintIntro(int Diff) {

	cout << "\n\nYou are a secret agent breaking into a super secured data center." << endl;
	cout << "You need to enter the correct codes to continue..." << endl;

}


bool PlayGame(int Diff) {

	int CodeA = rand() % Diff + 1; // + Diff
	int CodeB = rand() % Diff + 1;
	int CodeC = rand() % Diff + 1;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	cout << "\n\n+ There are 3 numbers in the code..." << endl;
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
		cout << "\n\n The correct code was " << CodeA << " " << CodeB << " " << CodeC;
		cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

		return true;
	}
	/*
	if (GuessA == 'help'){
		cout << "One of the numbers is " << CodeA;
		return false;
	}

	if (GuessA == 'dum') {
		cout << "Don't tell anyone, but the code is " << CodeA << " " << CodeB << " " << CodeC;
		return false;
	}
	*/
	else {
		cout << "\n \n Never mind, even legends have the bad days... Keep going!";
		cout << "\n\n The correct code was " << CodeA << " " << CodeB << " " << CodeC;
		cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

		return false;
	}

}


int main() {

	int LevelDiff = 1;
	const int MaxDiff = 10;

	// Create new random sequence (new seed for rand) based on time of day
	srand(time(NULL)); 

	PrintIntro(LevelDiff);

	while (LevelDiff <= MaxDiff) {

		cout << "\n\nLEVEL " << LevelDiff;

		bool bLevelComplete = PlayGame(LevelDiff);

		cin.clear(); // Clears any errors
		cin.ignore(); // Discards the buffer

		if (bLevelComplete){

			++LevelDiff;

		}

	}

	cout << "\n\n*** You are a fucking legend, you've done it!! ***\n\n";

	return 0;
}

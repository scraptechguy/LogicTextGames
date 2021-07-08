#include <iostream>
#include <ctime>
#include <algorithm>
#include <list>

using namespace std;

void PrintIntro(int Diff) {

	cout << "\n\nYou are a secret agent breaking into a super secured data center." << endl;
	cout << "You need to enter the correct codes to continue..." << endl;

}

bool bTopSecret = true;

int CodeA = 1;
int CodeB = 1;
int CodeC = 1;

int CodeSum = 1;
int CodeProduct = 1;


bool PlayGame(int Diff) {

	if (bTopSecret) {
		CodeA = rand() % Diff + 1; // + Diff
		CodeB = rand() % Diff + 1;
		CodeC = rand() % Diff + 1;

		CodeSum = CodeA + CodeB + CodeC;
		CodeProduct = CodeA * CodeB * CodeC;
	}

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

	list<string> PosResponses = {
		"Damn boi, you're on fire, you've got the file! Let's move on to the next one...",
		"Jeez, ain't they callin' you smartass? You've got the file! Let's move on to the next one...",
		"Gosh man, it's really not rocket science for you, is it? You've got the file! Let's move one to the next one..."
	};

	if (CodeSum == GuessSum && CodeProduct == GuessProduct) {
		cout << "\n\n Damn boi, you're on fire, you've got the file!Let's move on to the next one..."  ;
		cout << "\n\n The correct code was " << CodeA << " " << CodeB << " " << CodeC;
		cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

		bTopSecret = true;

		return true;
	}

	else if (GuessA == 0 && GuessB == 0 && GuessC == 7){
		cout << "\n\n*** TOP SECRET ***" << endl;
		cout << "\nDon't tell anyone how you know, but the code is " << CodeA << " " << CodeB << " " << CodeC << endl;
		cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

		bTopSecret = false;

		return false;
	}

	else {
		cout << "\n \n Never mind, even legends have the bad days... Keep going!";
		cout << "\n\n The correct code was " << CodeA << " " << CodeB << " " << CodeC;
		cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++";

		bTopSecret = true;

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


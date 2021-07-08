#include <iostream>
using namespace std;

int Num1;
int Num2;
char Op;
int Sol;


int main() {

	while (true) {
		

		cout << "\nEnter the first number: ";
		cin >> Num1;

		cout << "\nEnter the operator: ";
		cin >> Op;

		cout << "\nEnter the second number: ";
		cin >> Num2;


		if (Op == '+') {

			Sol = Num1 + Num2;
			cout << Num1 << Op << Num2 << " is " << Sol;
			cout << endl;
		}

		if (Op == '-') {

			Sol = Num1 - Num2;
			cout << Num1 << Op << Num2 << " is " << Sol;
			cout << endl;
		}

		if (Op == '*') {

			Sol = Num1 * Num2;
			cout << Num1 << Op << Num2 << " is " << Sol;
			cout << endl;

		}

		if (Op == '/') {

			Sol = Num1 / Num2;
			cout << Num1 << Op << Num2 << " is " << Sol;
			cout << endl;
		}
		cin.clear();
		cin.ignore();
	}
	return 0;
}


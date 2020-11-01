#include <iostream>
#include <cmath>
using namespace std;
 
//checks if the input is not a number
int LetterCheck() {
	int a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
		cout << "Error.\n You have to enter a whole number: ";
	}
	return a;
}

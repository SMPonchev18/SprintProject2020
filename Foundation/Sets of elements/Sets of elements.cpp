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

//function that you choose from which set of elements you want to work with
int SetChoice() 
{
	int option;
	cout << "Enter a valid option: ";
	option = LetterCheck();
	while (option < 1 or option > 2) {
		cout << "\nThere are only 2 sets you can choose from! Try again by typing 1 or 2. 1 is for the first set and 2 is for the second set: ";
		option = LetterCheck();
	}
	return option;
}

//input function for the elements in the set
void EnterSetEl(int *arr, int& size, string number)
{
	cout << "Enter size of the " << number << " set of numbers: ";
	size = LetterCheck();
	while (size < 1) {
		cout << "\nError.\nYou have to enter a whole number: ";
		size = LetterCheck();
	}
	cout << endl;
	cout << "Enter the " << number << " set of numbers: ";
	for (int i = 0; i < size; i++)
		arr[i] = LetterCheck();
	cout << endl;
}




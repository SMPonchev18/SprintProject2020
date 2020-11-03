#include <iostream>
#include <cmath>
using namespace std;


int firstSet[20], secondSet[20]; // Sets
int firstSize, secondSize;
char chosen;

//function that you choose from which set of elements you want to work with
void SetChoice()
{
	while (true)
	{
		cout << "Choose the first or the second set: ";
		char input; cin >> input;
		if (input == '1')
		{
			chosen = '1';
			break;
		}
		else if (input == '2')
		{
			chosen = '2';
			break;
		}
		else
		{
			cout << "Please choose 1 or 2: ";
			continue;
		}
	}
}

//input function for the elements in the set
void EnterSetEl()
{
	cout << "Enter the size of the first set: ";
	int num; 
	cin >> num; 
	cout << endl;
	firstSize = num;
	cout << "Enter numbers in the first set: ";
	for (int i = 0; i < num; i++)
	{
		cin >> firstSet[i];
	}
	cout << endl;
	cout << "Enter the size of the second set: ";
	cin >> num;
	secondSize = num;
	cout << endl;
	cout << "Enter numbers in second set: ";
	for (int i = 0; i < num; i++) {
		cin >> secondSet[i];
	}
	cout << endl << "Values have been assigned to both sets!" << endl;
}

//function that checks which numbers contain in both two sets of numbers
void Intersec()
{
	cout << "The numbers that are contained in both of the sets are: ";
	for (int i = 0; i < firstSize; i++)
	{
		for (int j = 0; j < secondSize; j++)
		{
			if (firstSet[i] == secondSet[j])
			{
				cout << firstSet[i] << " ";
			}
		}
	}
	cout << endl;
}

//function that displays which numbers from the first set do not contain in the second 
void Subtract()
{
	cout << "Numbers that do not contain in both sets: ";
	bool cont = false;
	for (int i = 0; i < firstSize; i++) {
		cont = false;
		for (int j = 0; j < secondSize; j++)
		{
			if (firstSet[i] == secondSet[j])
			{
				cont = true;
			}
		}
		if (cont == false) {
			cout << firstSet[i] << " ";
		}
	}
	for (int i = 0; i < secondSize; i++)
	{
		cont = false;
		for (int j = 0; j < firstSize; j++)
		{
			if (secondSet[i] == firstSet[j])
			{
				cont = true;
			}
		}
		if (cont == false)
		{
			cout << secondSet[i] << " ";
		}
	}
	cout << endl;
}

// a function that displays all the numbers from both sets and if there are number that are both in the two sets displays only one time
void Union()
{
	cout << "All numbers: ";
	bool cont = false;
	for (int i = 0; i < firstSize; i++)
	{
		cout << firstSet[i] << " ";
	}
	for (int i = 0; i < secondSize; i++)
	{
		cont = false;
		for (int j = 0; j < firstSize; j++)
		{
			if (secondSet[i] == firstSet[j])
			{
				cont = true;
			}
		}
		if (cont == false)
		{
			cout << secondSet[i] << " ";
		}
	}
	cout << endl;
}


// a function that shows a greeting message to all the users
void Hello()
{
	cout << " _______________________\n";
	cout << "|                       |\n";
	cout << "|       Welcome to      |\n";
	cout << "|          our          |\n";
	cout << "|        project        |\n";
	cout << "|_______________________|\n\n";
	cout << " _________\n";
	cout << "|         |\n";
	cout << "|To start:|\n";
	cout << "|_________|\n\n\n";
}

// function that shows all the options of our program
void Options()
{
	cout << "--------------/ Options /-------------\n\n";
	cout << "1. ----- Intersection (Sechenie) -----\n";
	cout << "2. ----- Subtraction (Razlika) -------\n";
	cout << "3. -------- Union (Obedinenie)--------\n";
	cout << "4. ------------- Exit ---------------- \n\n";
	cout << "Enter a valid option: ";
}

// The main function
int main()
{
	Hello();
	EnterSetEl();
	char input;
	while (true)
	{
		Options();
		cin >> input;
		if (input == '1')
		{
			Intersec();
		}
		else if (input == '2')
		{
			Subtract();
		}
		else if (input == '3')
		{
			Union();
		}
		else if (input == '4')
		{
			cout << "\nThank you for using our program!\n\n";
			return 0;
		}
		else
		{
			cout << "Please enter a valid option from 1 to 4!";
		}
	}
	
	system("pause");
}


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

//function that compares the numbers in both two sets of numbers depending on the given action by the user 
int* compareSets(int *arr, int n, int *arr2, int m, string action, int *a, int &k)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i] == arr2[j])
			{
				counter++;
			}
		}
		if (action == "!=")
		{
			if (counter != 0)
			{
				a[k] = arr[i];
				k++;
			}
		}
		else if (action == "==")
		{
			if (counter == 0)
			{
				a[k] = arr[i];
				k++;
			}
		}
		counter = 0;
	}
	return a;
}

//function that checks which numbers contain in both two sets of numbers
void Intersec(int *arr, int n, int *arr2, int m)
{
	cout << "The intersection of the sets A and B is: ";
	int* c = new int[(double)n + m];
	int k = 0;
	compareSets(arr, n, arr2, m, "!=", c, k);
	for (int i = 0; i < k; i++)
		cout << c[i] << " ";
	delete[]c;
}

//function that displays which numbers from the first set don't contain in the second 
void Substract(int *arr, int n, int *arr2, int m)
{
	int* c = new int[(double)n + m];
	int k = 0;
	cout << "Choose from which set of numbers you want to subtract from?\n";
	cout << "1. The first - A\n";
	cout << "2. The second - B\n";
	if (SetChoice() == 1) {
		cout << "\nThe subtraction of the sets A and B is: ";
		compareSets(arr, n, arr2, m, "==", c, k);
	}
	else
	{
		cout << "\nThe subtraction of the sets B a A is: ";
		compareSets(arr2, m, arr, n, "==", c, k);
	}
	for (int i = 0; i < k; i++)
		cout << c[i] << " ";
	delete[]c;

}

// a function that displays all the numbers from both sets and if there are number that are both in the two sets displays only one time
void Union(int *a, int n, int* b, int m)
{
	cout << "The union of the sets A and B is: ";
	int* c = new int[(double)n + m];
	int k = 0;
	for (int i = 0; i < n; i++) 
	{
		c[k] = a[i];
		k++;
	}
	compareSets(b, m, a, n, "==", c, k);
	for (int i = 0; i < k; i++)
	{
		cout << c[i] << " ";
	}
	delete[]c;
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

// this is the main menu of the program 
void Menu()
{
    Hello();
    int a[200], b[200], n, m;
    EnterSetEl(a, n, "first");
    EnterSetEl(b, m, "second");
    int numchoice;
    do
    {
        Options();
        numchoice = LetterCheck();
        while ((numchoice < 1) or (numchoice > 4))
        {
            cout << "\nError. You have to enter a number between 1 and 4:\n ";
            numchoice = LetterCheck();
        }
 
        cout << endl;
 
        switch (numchoice)
        {
        case 1:
            Intersec(a, n, b, m);
            break;
 
        case 2:
            Substract(a, n, b, m);
            break;
 
        case 3:
            Union(a, n, b, m);
            break;
 
        case 4:
            cout << "Bye!\n";
            break;
        }
        cout << endl << endl;;
    } while (numchoice != 4);
}

// The main function
int main()
{
    Menu();
}
 

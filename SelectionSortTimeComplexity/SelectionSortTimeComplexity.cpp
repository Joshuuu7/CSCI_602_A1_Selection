/***********************************************************************************/
/* Course - Assignment - Semester: CSCI 602 - Assignment 1 - Spring 2020           */
/*                                                                                 */
/* Progammer: Flores, Joshua A.                                                    */
/* Z-ID: z1682720                                                                  */
/* Section: 1                                                                      */
/* Date Due: January 28, 2020                                                      */
/*                                                                                 */
/* Purpose: This program takes one mandatory and two optional arguments. It        */
/* creates an array of a specific size (otherwise the default) and sorts in        */
/* ascending, descending, or random order. Finally, it sorts the array in          */
/* ascending order (if not already sorted in ascending order) using the selection  */
/* sort mechanism.                                                                 */
/***********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

const int DEF_SIZE = 7;
const string DEF_ORDER = "R";

void error();
void ascending(int n);
void descending(int n);
void random(int n);
void chooseFunction(int n = DEF_SIZE, string s = DEF_ORDER);
void selectionSort(int * p, int s);
int findMin(int * p, int j, int n);
void printArray(int * p, int s);

int main(int argc, char** argv)
{
	string order;
	string size = "";
	int strToInt_Sz = 0;

	/*Takes the arguments from the command line and determines which type of call is required.
	Defaults to command with two arguments (the name of the executable program and the argument
	for the algorithm). The last argument is, however, useless as the purpose of each module is 
	to focus on one algorithm specifically. Therefore, even though "S" is selected, it will always 
	run insertion, to avoid confusion. This is the purpose of the two separate module, as specified 
	in the assignment.
	*/
	if (argc == 3) {
		cin >> argv[1];
		size = argv[1];
		strToInt_Sz = stoi(size);
		cin >> argv[2];
		order = *argv[2];
		chooseFunction(strToInt_Sz, order);
	}
	else if (argc == 2) {
		cin >> argv[1];
		if ((int)*argv[1]) {
			size = argv[1];
			strToInt_Sz = stoi(size);
			chooseFunction(strToInt_Sz, DEF_ORDER);
		}
		else {
			order = argv[1];
			cout << endl;
			chooseFunction(DEF_SIZE, order);
		}
	}
	else {
		chooseFunction(DEF_SIZE, DEF_ORDER);
	}
}

void error() {
	cout << "ERROR: Please enter a positive number!" << endl;
}

void ascending(int n) {
	int size = 0;

	if (n > 1) {
		int *array = new int[n];
		for (int j = 0; j <= n - 1; j++) {
			array[j] = j;
			cout << "a[" << j << "] = " << array[j] << endl;
			size = j + 1;

		}
		cout << "Array Size: " << size << endl;
		selectionSort(array, size);
	}
	else {
		error();
	}
}

void descending(int n) {
	int size = 0;

	if (n > 1) {
		int *array = new int[n];
		for (int j = 0; n - 1 >= 0; j++) {
			n--;
			array[j] = n;
			cout << "a[" << j << "] = " << array[j] << endl;
			size = j + 1;
		}
		cout << "Array Size: " << size << endl;
		selectionSort(array, size);
	}
	else {
		error();
	}
}

void random(int n) {
	int size = 0;

	/* This will create an array with all random numbers.*/
	if (n > 1) {
		int *array = new int[n];
		srand((unsigned)time(0));
		for (int j = 0; n - 1 >= 0; j++) {
			n--;
			array[j] = (rand() % 1000) + 1;
			cout << "a[" << j << "] = " << array[j] << endl;
			size = j + 1;
		}
		cout << "Array Size: " << size << endl;
		selectionSort(array, size);
	}
	else {
		error();
	}
}

void chooseFunction(int n, string s) {

	// Conditional statements to run the program depending on the provided argument for sorting order.
	if (s.compare("A") == 0) {
		ascending(n);
	}
	else if (s.compare("D") == 0) {
		descending(n);
	}
	else {
		random(n);
	}
}

void selectionSort(int * p, int n) {

	cout << endl << "Selection Sort" << endl;
	cout << "-----------------------" << endl;

	/* min is initially set to the array's first element.
	The following loop will compare min to other values
	in the array, update min with the current
	newest value, and swap both.
	*/

	int min = 0;
	for (int i = 0; i <= n - 1; i++) {
		int minIndex = findMin(p, i, n);
		min = p[minIndex];
		p[minIndex] = p[i];
		p[i] = min;
	}
	printArray(p, n);
}

int findMin(int * p, int j, int n) {
	
	int newMin = j;
	for (int i = j + 1; i < n; i++) {
		if (p[i] < p[newMin]) {
			newMin = i;
		}
	}
	return newMin;
}

void swap(int min, int p) {
	
}

void printArray(int * p, int s) {
	for (int o = 0; o < s; o++) {
		cout << "a[" << o << "] = " << p[o] << endl;
	}
}


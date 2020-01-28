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
/* ascending order (if not already sorted in ascending order) using selection      */
/* sort mechanisms.                                                                */
/***********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

const int DEF_SIZE = 1000;
const char DEF_ORDER = 'R', INSERT = 'I';

void error();
void ascending(int n);
void descending(int n);
void random(int n);
void chooseFunction(int n = DEF_SIZE, char s = DEF_ORDER, char g = 'I');
void selectionSort(int arr[], int s);

int main()
{
	char size_option, order_option, order, rerun;
	string size = "";

	int charToInt = 0;
	cout << "Would you like to choose a size (Y/N)?" << endl;
	cin >> size_option;
	if (size_option == 'Y') {
		cout << "Enter the array size: " << endl;
		cin >> size;
		int strToInt_Sz = stoi(size);
		cout << endl;
		cout << "Would you like to choose an order (Y/N)?" << endl;
		cin >> order_option;
		if (order_option == 'Y') {
			cout << "Enter sorting order: " << endl;
			cin >> order;
			chooseFunction(strToInt_Sz, order, 'I');
		}
		else {
			chooseFunction(strToInt_Sz, DEF_ORDER, 'I');
		}
	}
	else {
		cout << "Would you like to choose an order (Y/N)?" << endl;
		cin >> order_option;
		if (order_option == 'Y') {
			cout << "Enter sorting order: " << endl;
			cin >> order;
			chooseFunction(DEF_SIZE, order, 'I');
		}
		else {
			chooseFunction(DEF_SIZE, DEF_ORDER, 'I');
		}
	}
}

void error() {
	cout << "ERROR: Please enter a positive number!" << endl;
}

void reRun() {
	char rerun;
	cout << "Run again?" << endl;
	cin >> rerun;
	if (rerun == 'Y') {
		main();
	}
}

void ascending(int n) {
	int * arr;
	int size = 0;
	if (n > 1) {
		arr = new (nothrow) int[n];
		for (int j = 0; j <= n - 1; j++) {
			arr[j] = j;
			cout << "a[" << j << "] = " << arr[j] << endl;
		}
		size = sizeof(arr);
		cout << "Array Size: " << size << endl;
		selectionSort(arr, size);
	}
	else {
		error();
	}
}

void descending(int n) {
	int * arr, size = 0;

	if (n > 1) {
		arr = new (nothrow) int[n];
		for (int j = 0; n - 1 >= 0; j++) {
			n--;
			arr[j] = n;
			cout << "a[" << j << "] = " << arr[j] << endl;
			selectionSort(arr, INSERT);
		}
		size = sizeof(arr);
		cout << "Array Size: " << size << endl;
		selectionSort(arr, size);
	}
	else {
		error();
	}
}

void random(int n) {
	int * arr, size = 0;

	if (n > 1) {
		arr = new (nothrow) int[n];
		srand((unsigned)time(0));
		for (int j = 0; n - 1 >= 0; j++) {
			n--;
			arr[j] = (rand() % 1000) + 1;
			cout << "a[" << j << "] = " << arr[j] << endl;
			selectionSort(arr, INSERT);
		}
		size = sizeof(arr);
		cout << "Array Size: " << size << endl;
		selectionSort(arr, size);
	}
	else {
		error();
	}
}

void chooseFunction(int n, char s, char g) {

	if (s) {
		if (s == 'A') {
			ascending(n);
			reRun();
		}
		else if (s == 'D') {
			descending(n);
			reRun();
		}
		else {
			random(n);
			reRun();
		}
	}
}

void selectionSort(int arr[], int s) {
	int key = 0;
	for (int i = 2; i <= s; i++) {
		key = arr[i];
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

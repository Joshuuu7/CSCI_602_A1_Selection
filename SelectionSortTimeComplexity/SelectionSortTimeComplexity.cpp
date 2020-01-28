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

const int DEF_SIZE = 1000;
const char DEF_ORDER = 'R';

void error();
void ascending(int n);
void descending(int n);
void random(int n);
void chooseFunction(int n = DEF_SIZE, char s = DEF_ORDER);
void selectionSort(int * p, int s);
void printArray(int * p, int s);

int main()
{
	char size_option, order_option, order;
	string size = "";

	cout << "Would you like to choose a size (Y/N)?" << endl;
	cin >> size_option;
	cout << endl;
	if (size_option == 'Y') {
		cout << "Enter the array size: " << endl;
		cin >> size;
		int strToInt_Sz = stoi(size);
		cout << endl;
		cout << "Would you like to choose an order (Y/N)?" << endl;
		cin >> order_option;
		cout << endl;
		if (order_option == 'Y') {
			cout << "Enter sorting order: " << endl;
			cin >> order;
			cout << endl;
			chooseFunction(strToInt_Sz, order);
		}
		else {
			chooseFunction(strToInt_Sz, DEF_ORDER);
		}
	}
	else {
		cout << "Would you like to choose an order (Y/N)?" << endl;
		cin >> order_option;
		cout << endl;
		if (order_option == 'Y') {
			cout << "Enter sorting order: " << endl;
			cin >> order;
			cout << endl;
			chooseFunction(DEF_SIZE, order);
		}
		else {
			chooseFunction(DEF_SIZE, DEF_ORDER);
		}
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

void chooseFunction(int n, char s) {
	if (s) {
		if (s == 'A') {
			ascending(n);
		}
		else if (s == 'D') {
			descending(n);
		}
		else {
			random(n);
		}
	}
}

void selectionSort(int * p, int s) {

	int loop;
	cout << endl << "Selection Sort" << endl;
	cout << "---------------------- - " << endl;
	int min = p[0];
	for (int j = 0; j < s - 1; j++) {
		if (min > p[j]) {
			min = p[j];
		}
	}
	p[0] = min;

	while (1) {
		loop = 0;
		for (int i = 1; i <= s - 1; i++) {
			if (p[i - 1] > p[i]) {
				int next = p[i - 1];
				p[i - 1] = p[i];
				p[i] = next;
				loop = 1;
			}
		}
		if (loop == 0) {
			break;
		}
	}
	printArray(p, s);
}
 
void printArray(int * p, int s) {
	for (int o = 0; o < s; o++) {
		cout << "array[" << o << "] = " << p[o] << endl;
	}
}

//void selectionSort(int * p, int s) {
//	cout << endl << "Selection Sort" << endl; 
//	cout << "---------------------- - " << endl;
// 	int * array = new int[s];
//	for (int i = 1; i <= s - 1; i++) {
//		int min = p[i - 1];
//		if (min > p[i]) {
//			min = p[i];
//			if (min > array[i] && array[i - 1] > array[i]) {
//				array[i - 1] = min;
//				array[i] = min;
//				if (array[i - 1] > array[i]) {
//					array[i - 1] = array[i];
//					array[i] = array[i - 1];
//				}
//			}
//		}
//		else {
//			array[i] = p[i];
//		}
//		cout << "array[" << i - 1 << "] = " << array[i - 1] << endl;
//	}
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

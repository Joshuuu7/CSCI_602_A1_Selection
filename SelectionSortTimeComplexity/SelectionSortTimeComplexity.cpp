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
const string DEF_ORDER = "R";

void error();
void ascending(int n);
void descending(int n);
void random(int n);
void chooseFunction(int n = DEF_SIZE, string s = DEF_ORDER);
void selectionSort(int * p, int s);
void printArray(int * p, int s);

int main(int argc, char** argv)
{
	string order;
	string size = "";
	int strToInt_Sz = 0;

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

void selectionSort(int * p, int s) {

	int loop, replaced;
	cout << endl << "Selection Sort" << endl;
	cout << "---------------------- - " << endl;
	int min = p[0];

	for (int j = 0; j < s - 1; j++) {
		if (min > p[j]) {
			replaced = min;
			min = p[j];
			p[j] = replaced;
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
			if (p[i - 1] == p[i]) {
				continue;
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
		cout << "a[" << o << "] = " << p[o] << endl;
	}
}


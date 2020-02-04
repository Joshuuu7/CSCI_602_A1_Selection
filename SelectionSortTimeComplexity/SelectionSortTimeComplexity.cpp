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
#include <cstring>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

const int DEF_SIZE = 1000;
const string LEADING_NUM_TOKEN = "N", LEADING_SORT_TOKEN = "S", LEADING_ALG_TOKEN = "G",
DEF_ORDER = "R", DEF_ALG = "S", DELIMITER = "=", ALGORITHM_TYPE = "selection";

bool checkLeadingTokens(string n, string s, string g);
string getLeadingToken(string str);
string getToken(string str);
bool is_number(const string &s);
void checkSelectArg(int strToInt_Sz, string sortToken, string selAlg);
void error(string message);
void ascending(int n);
void descending(int n);
void random(int n);
void chooseSortOrder(int n = DEF_SIZE, string s = DEF_ORDER);
void selectionSort(int *p, int s);
int findMin(int * p, int j, int n);
void printArray(int *p, int s);

int main(int argc, char **argv)
{
	string leading_num = "", leading_sort = "", leading_alg = "",
		number = "", sort = "", selAlg = "",
		numberToken = "", sortToken = "", selAlgToken = "",
		firstArg = "", firstArgToken = "";
	int strToInt_Sz = 0;
	bool leading_Tokens = false, is_num = false;

	/*Takes the arguments from the command line and determines which type of call is required.
	Defaults to command with two arguments (the name of the executable program and the argument
	for the algorithm). The last argument is, however, useless as the purpose of each module is
	to focus on one algorithm specifically. Therefore, even though "I" is selected, it will always
	run selection, to avoid confusion. This is the purpose of the two separate module, as specified
	in the assignment.
	*/

	if (argc == 4)
	{
		leading_num = getLeadingToken(argv[1]);
		leading_sort = getLeadingToken(argv[2]);
		leading_alg = getLeadingToken(argv[3]);
		leading_Tokens = checkLeadingTokens(leading_num, leading_sort, leading_alg);
		if (leading_Tokens == true)
		{
			firstArg = argv[1];
			firstArgToken = getToken(firstArg);
			is_num = is_number(firstArgToken);
			if (is_num)
			{
				number = argv[1];
				numberToken = getToken(number);
				strToInt_Sz = stoi(numberToken);
				if (strToInt_Sz > 1)
				{
					sort = argv[2];
					selAlg = argv[3];
					sortToken = getToken(sort);
					selAlgToken = getToken(selAlg);
					checkSelectArg(strToInt_Sz, sortToken, selAlgToken);
				}
				else
				{
					error("Number must be positive!");
				}
			}
		}
	}
	else if (argc == 3) {
		firstArg = argv[1];
		firstArgToken = getToken(firstArg);
		is_num = is_number(firstArgToken);
		if (is_num) {
			leading_num = getLeadingToken(argv[1]), leading_alg = getLeadingToken(argv[2]);
			leading_Tokens = checkLeadingTokens(leading_num, LEADING_SORT_TOKEN, leading_alg);
			if (leading_Tokens == true)
			{
				strToInt_Sz = stoi(firstArgToken);
				if (strToInt_Sz > 1)
				{
					selAlg = argv[2];
					selAlgToken = getToken(selAlg);
					checkSelectArg(strToInt_Sz, DEF_ORDER, selAlgToken);
				}
			}
		}
		else {
			leading_sort = getLeadingToken(argv[1]), leading_alg = getLeadingToken(argv[2]);
			leading_Tokens = checkLeadingTokens(LEADING_NUM_TOKEN, leading_sort, leading_alg);
			if (leading_Tokens == true) {
				sort = argv[1];
				sortToken = getToken(sort);
				selAlg = argv[2];
				selAlgToken = getToken(selAlg);
				checkSelectArg(DEF_SIZE, sortToken, selAlgToken);
			}
		}
	}
	else if (argc == 2)
	{
		leading_alg = getLeadingToken(argv[1]);
		leading_Tokens = checkLeadingTokens(LEADING_NUM_TOKEN, LEADING_SORT_TOKEN, leading_alg);
		if (leading_Tokens == true)
		{
			selAlg = argv[1];
			selAlgToken = getToken(selAlg);
			checkSelectArg(DEF_SIZE, DEF_ORDER, selAlgToken);
		}
	}
	else
	{
		error("The argument G=" + DEF_ALG + " is mandatory.");
	}
}

bool checkLeadingTokens(string n, string s, string g)
{
	if (n.compare(LEADING_NUM_TOKEN) != 0)
	{
		error("The first leading parameter token must be '" + LEADING_NUM_TOKEN + "'. Enter the valid leading parameters (N S G) in that order.");
		return false;
	}
	if (s.compare(LEADING_SORT_TOKEN) != 0)
	{
		error("The second leading parameter token must be '" + LEADING_SORT_TOKEN + "'. Enter the valid leading parameters (N S G) in that order.");
		return false;
	}
	if (g.compare(LEADING_ALG_TOKEN) != 0)
	{
		error("The third leading parameter token must be '" + LEADING_ALG_TOKEN + "'. Enter the valid leading parameters (N S G) in that order.");
		return false;
	}
	return true;
}

string getLeadingToken(string str)
{
	string leadingToken = str.substr(0, str.find(DELIMITER));
	return leadingToken;
}

string getToken(string str)
{
	string token = str.substr(str.find(DELIMITER) + 1);
	return token;
}

bool is_number(const string &s)
{
	return (strspn(s.c_str(), "0123456789") == s.size());
}

void checkSelectArg(int strToInt_Sz, string sortToken, string selAlg)
{
	string selAlgToken = getToken(selAlg);
	if (selAlgToken.compare(DEF_ALG) == 0)
	{
		chooseSortOrder(strToInt_Sz, sortToken);
	}
	else
	{
		error("This is module supports " + ALGORITHM_TYPE + " sorting only! Provide argument G=" + DEF_ALG + ".");
	}
}

void error(string message = "Enter a positive number!")
{
	cerr << "ERROR: " + message << endl;
}

void ascending(int n)
{

	cout << endl;
	cout << "Command [N=" << n << "] [S=A] "
		<< "G=" << DEF_ALG << " executed." << endl
		<< endl;
	int size = 0;
	if (n > 1)
	{
		int *array = new int[n];
		for (int j = 0; j <= n - 1; j++)
		{
			array[j] = j;
			size = j + 1;
		}
		printArray(array, n);
		cout << "Array Size: " << size << endl;
		selectionSort(array, size);
	}
	else
	{
		error();
	}
}

void descending(int n)
{

	cout << endl;
	cout << "Command [N=" << n << "] [S=D] "
		<< "G=" << DEF_ALG << " executed." << endl
		<< endl;
	int size = 0;
	if (n > 1)
	{
		int *array = new int[n];
		for (int j = 0; n - 1 >= 0; j++)
		{
			n--;
			array[j] = n;
			size = j + 1;
		}
		printArray(array, size);
		cout << "Array Size: " << size << endl;
		selectionSort(array, size);
	}
	else
	{
		error();
	}
}

void random(int n)
{

	cout << endl;
	cout << "Command [N=" << n << "] [S=R] "
		<< "G=" << DEF_ALG << " executed." << endl
		<< endl;
	int size = 0;
	/* This will create an array with all random numbers.*/
	if (n > 1)
	{
		int *array = new int[n];
		srand((unsigned)time(0));
		for (int j = 0; n - 1 >= 0; j++)
		{
			n--;
			array[j] = (rand() % 1000) + 1;
			size = j + 1;
		}
		printArray(array, size);
		cout << "Array Size: " << size << endl;
		selectionSort(array, size);
	}
	else
	{
		error();
	}
}

void chooseSortOrder(int n, string s)
{

	// Conditional statements to run the program depending on the provided argument for sorting order.
	if (s.compare("A") == 0)
	{
		ascending(n);
	}
	else if (s.compare("D") == 0)
	{
		descending(n);
	}
	else if (s.compare("R") == 0)
	{
		random(n);
	}
	else if (s.compare("A") != 0 || s.compare("D") != 0 || s.compare("R") != 0)
	{
		error("Provide only valid optional parameters (S=A, S=D, or S=R) /n or leave the optional field blank for the defualt random sorting.");
	}
	else
	{
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

void printArray(int *p, int s)
{
	for (int o = 0; o < s; o++)
	{
		cout << "A[" << o << "] = " << p[o] << endl;
	}
}

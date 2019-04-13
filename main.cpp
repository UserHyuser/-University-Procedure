#include <iostream>
#include <fstream>
#include "container_atd.h"

using namespace std;
using namespace simple_animals;

namespace simple_animals {
	// Signatures of using external functions
	void Init(container &c);
	void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void OnlyFish(container &c, ofstream &ofst);
	void MultiMethod(container &c, ofstream &ofst);
	void Sort(container &c);
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect command line! "
			"Waited: command infile outfile" << endl;
		return -1;
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	// Check in.txt
	if (!ifst.is_open())
	{
		cout << "Error opening in.txt";
		return -1;
	}
	// Check out.txt
	if (!ofst.is_open())
	{
		cout << "Error opening out.txt";
		return -1;
	}
	// Check in.txt content
	int i = 0; // Current string number
	char* buferStr = new char;
	int typeAnimal;
	int param;
	char bufName[21];
	int bufAge;
	int error_code = 0;
	int bufArrayLength = 0;

	while (!ifst.eof())
	{
		switch (i % 4) {
		case 0:
			i++;
			if (!(ifst >> typeAnimal) || ((typeAnimal < 1) || (typeAnimal > 3))) // Error trying read integer or incorrect key
			{
				cout << "Error. Wrong type. Parametr #" << i << "." << endl;
				return -1;
			}
			break;
		case 1:
			i++;
			if (!(ifst >> param)) // Error trying read integer
			{
				cout << "Error. Wrong parameter. Parametr #" << i << "." << endl;
				return -1;
			}
			// Integer is read, but parameter is wrong
			if (((typeAnimal == 1) && !((param == 1) || (param == 0))) ||
				((typeAnimal == 2) && !((param == 0) || (param == 1) || (param == 2))) ||
				((typeAnimal == 3) && !((param == 0) || (param == 1) || (param == 2))))
			{
				cout << "Error. Wrong parameter. Parametr #" << i << "." << endl;
				return -1;
			}
			break;
		case 2:
			i++;
			if (!(ifst >> bufName)) 
			{
				cout << "Error. Wrong name. Parametr #" << i << "." << endl;
				return -1;
			}
			break;
		case 3:
			i++;
			if (!(ifst >> bufAge) || (bufAge > 200 || bufAge < 0)) 
			{
				cout << "Error. Wrong age. Parametr #" << i << "." << endl;
				return -1;
			}
			break;
		}
	}

	if (i % 4 != 0) {
		cout << "Not enough parametrs. " << endl;
		return -1;
	}

	// Check is finished withot errors
	// Reopening file
	ifst.close();
	ifst.open(argv[1]);

	cout << "Start" << endl;
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Container is filled. " << endl;
	Sort(c);
	Out(c, ofst);
	OnlyFish(c, ofst);
	MultiMethod(c, ofst);
	Clear(c);
	ofst << "Container is empty. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	system("pause");
	return 0;
}

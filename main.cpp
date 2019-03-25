#include <iostream>
#include <fstream>
#include "container_atd.h"
#include "animal_atd.h"
//#include "containers.cpp"


using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	ifstream in;
	in.open("in.txt");
	if (!in.is_open())
	{
		cout << "Ошибка с файлом";
		return -1;
	}

	ofstream out;
	out.open("out.txt");
	if (!out.is_open())
	{
		cout << "Ошибка с файлом";
		return -1;
	}

	cout << "Start" << endl;

	simple_animals::container* begin = new simple_animals::container;
	begin->In(in);
	begin->Sort();
	begin->OnlyFish(out);
	begin->Out(out);

	cout << "Stop" << endl;

	in.close();
	out.close();
	system("pause");
	return 0;
}
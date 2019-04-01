#include <iostream>
#include <fstream>
#include "conteiner.h"

using namespace std;

namespace simple_animals {
// Ñèãíàòóðû òðåáóåìûõ âíåøíèõ ôóíêöèé
void Init(container &c) ;
void Clear(container &c);
void In(container &c, ifstream &ifst) ;
void Out(container &c, ofstream &ofst) ;

void OnlyFish(container &c, ofstream &ofst);

void Sort(container &c);

}

using namespace simple_animals;

int main(int argc, char* argv[]) 
{
	if(argc !=3)	
	{
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	//Начало проверок
	//Проверка наличия файла входных данных
	if (!ifst.is_open())
	{
		cout << "Error opening in.txt";
		return -5;
	}
	//Проверка возможности создания файла выходных данных
	if (!ofst.is_open())
	{
		cout << "Error opening out.txt";
		return -6;
	}
	//Проверка содержимого входного файла
	int i = 0; //Номер строки, которую будем считывать
	char* buferStr = new char; //Буфер для строки
	int typeAnimal; //Тип шифра, с которым работаем
	int param; //Параметр шифра, с которым работаем
	char bufName[21]; //Исходный текст шифра, с которым работаем
	int bufAge; //Возраст
	int error_code = 0; //Код ошибки
	int bufArrayLength = 0;
	//Цикл проверки
	while (!ifst.eof() && (error_code == 0))
	{
		switch (i % 4) {
		case 0:
			if (!(ifst >> typeAnimal)) // Нельзя считать число
			{
				if (!(ifst >> buferStr) && (i > 0) && (typeAnimal!= 0)) // Конец данных и не пустой файл - ошибки нет
					goto noerrors;
				else  // Пустой файл или ошибка в данных
				{
					error_code = 1;
				}
			}
			else
			{
				if ((typeAnimal < 1) || (typeAnimal > 3)) // Ошибка в данных
				{
					error_code = 1;
				}
			}
			i++;
			break;
		case 1:
			if (!(ifst >> param)) error_code = 2;	// Внезапный конец файла или не число
			if ((typeAnimal == 1) && !((param == 1) || (param == 0))) error_code = 2; // Несоответствие параметра допустимым ключам 1, 2, 3
			if ((typeAnimal == 2) && !((param == 0) || (param == 1) || (param == 2))) error_code = 2; // Несоответствие параметра допустимым сдвигам (неотрицательное)
			if ((typeAnimal == 3) && !((param == 0) || (param == 1) || (param == 2))) error_code = 2; // Несоответствие параметра допустимым числам (неотрицательное)
			i++;
			break;
		case 2:
			if (!(ifst >> bufName)) error_code = 3; // Внезапный конец файла 
			
			bufArrayLength = 0;
			for (int i = 0; bufName[i]; i++) {
				bufArrayLength++;
			}
			if (bufArrayLength > 20) error_code = 3;
			i++;
			break;
		case 3:
			if (!(ifst >> bufAge)) error_code = 4; // Внезапный конец файла 
			if (bufAge > 200 || bufAge < 0) {
				error_code = 4;
			}
			i++;
			break;
		}
	}
	// Определение типа ошибки
	switch (error_code) {
	case 1:
		cout << "Error. Wrong type. Parametr #" << i%4 << "." << endl;
		system("pause");
		return 0;
		break;
	case 2:
		cout << "Error. Wrong parameter. Parametr #" << i % 4 << "." << endl;
		system("pause");
		return 0;
		break;
	case 3:
		cout << "Error. Wrong name. Parametr #" << i % 4 << "." << endl;
		system("pause");
		return 0;
		break;
	case 4:
		cout << "Error. Wrong age. Parametr #" << i % 4 << "." << endl;
		system("pause");
		return 0;
		break;
	}

	// Проверка оконечна без ошибок
	noerrors:;
	// Переоткрытие файла входных данных
	ifst.close();
	ifst.open(argv[1]);

	cout << "Start"<< endl;
	container c;
	Init(c);
	In(c, ifst);
    ofst << "Çàïîëíåííûé êîíòåéíåð. " << endl;
  
	Sort(c);
  
	OnlyFish(c, ofst);
	ofst << "Òåïåðü íå òîëüêî ðûáû. " << endl;

  Out(c, ofst);
	Clear(c);
    //ofst << "Ïóñòîé êîíòåéíåð. " << endl;
	//Out(c, ofst);
	cout << "Stop"<< endl;
	system ("pause");
return 0;
}

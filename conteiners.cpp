#include "conteiner.h"
#include "animal_atd.h"
#include <fstream>

using namespace std;

namespace simple_animals {
  // Инициализация контейнера
  void Init(container &c) { c.len = 0; }
  // Очистка контейнера от элементов 
  // (освобождение памяти)

  void Clear(container &c) {
    for(int i = 0; i < c.len; i++){
      delete c.cont[i];
    }
    c.len = 0;
  }
  // Сигнатуры требуемых внешних функций
  animal *In(ifstream &ifdt);

  // Ввод содержимого контейнера из указанного потока
  void In(container &c, ifstream &ifst) {
    while(!ifst.eof()) 
	{
	  if (c.len > 99)
	  {
		  break;
	  }
	  else
	  {
		  if((c.cont[c.len] = In(ifst)) != 0)
	  		  c.len++; 
	  }
    }

  }
  // Сигнатуры требуемых внешних функций

  void Out(animal &s, ofstream &ofst);
  // Вывод содержимого контейнера в указанный поток
  void Out(container &c, ofstream &ofst) 
  {
	ofst << "Контейнер содержит " << c.len 
	<< " животных." << endl;
    for(int i = 0; i < c.len; i++) 
	{
      ofst << i << ": ";
      Out(*(c.cont[i]), ofst);
    }
  }
} // end simple_animals namespace





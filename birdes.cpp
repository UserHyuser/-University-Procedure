#include <fstream>
#include "bird_atd.h"

using namespace std;

namespace simple_animals 
{
	
	// Ввод параметров прямоугольника из файла
  void In(bird &r, ifstream &ifst)
  {
    ifst >> r.fly;
  }

  int LenghtName(bird &r, char name[20]) {
	  int arrayLength = 0;
	  for (int i = 0; name[i]; i++) {
		  arrayLength++;
	  }
	  return arrayLength;
  }

  // Вывод параметров прямоугольника 
  void Out(bird &r, char name[20] ,ofstream &ofst) 
  {
	  if (r.fly == 0) {
		  ofst << "Это неперелетная птица "<< name << endl;
	  }
	  else {
		  ofst << "Это перелетная птица " << name << endl;
	  }
  }
} // end simple_animals namespace



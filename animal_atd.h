#ifndef __animal_atd__
#define __animal_atd__
// Подключение необходимых типов данных
#include "bird_atd.h"
#include "fish_atd.h"
#include "beast_atd.h"
namespace simple_animals {
  // структура, обобщающая все имеющиеся фигуры
  struct animal {
    // значения ключей для каждой из фигур
    enum key {BIRD, FISH, BEAST};
    key k; // ключ
	char name[20];
	int age = 0;
    // используемые альтернативы
    union { // используем включение
      bird r;
      fish t;
	  beast b;
    };
  };
} // end simple_animals namespace
#endif

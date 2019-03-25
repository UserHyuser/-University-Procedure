#pragma once
#ifndef __beast_atd__
#define __beast_atd__
// Требеутся описание класса animal
#include "animal_atd.h"
namespace simple_animals {
	// животное
	class beast : public animal {
		
		int eat; // хищник - 0 травоядное - 1 насекомоядное -2
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst);  // ввод
		void Out(ofstream &ofst);    // вывод 
		int LenghtName();
		beast() {} // создание без инициализации.
	};
} // end simple_animals namespace
#endif

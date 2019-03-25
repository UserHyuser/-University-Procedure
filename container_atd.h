
#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "animal_atd.h"
namespace simple_animals {
	// Ïðîñòåéøèé êîíòåéíåð íà îñíîâå îäíîìåðíîãî ìàññèâà
	class container {
		enum { max_len = 100 }; // ìàêñèìàëüíàÿ äëèíà
		int len; // òåêóùàÿ äëèíà
		animal *cont[max_len];
	public:
		void In(ifstream &ifst);     // ââîä 
		void Out(ofstream &ofst);    // âûâîä 
		void LenghtName(ofstream &ofst);
		void Sort();
		void Clear();  // î÷èñòêà êîíòåéíåðà îò ôèãóð
		void OnlyFish(ofstream &ofst);
    container();    // èíèöèàëèçàöèÿ êîíòåéíåðà
		~container() { Clear(); } // óòèëèçàöèÿ êîíòåéíåðà
	};
} // end simple_animals namespace
#endif


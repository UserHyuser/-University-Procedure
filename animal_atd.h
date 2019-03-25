#pragma once
#ifndef __animal_atd__
#define __animal_atd__
#include <fstream>
using namespace std;
namespace simple_animals {
	// �����, ����������� ��� ��������� ������.
	// �������� �����������, �����������, ��� �����, 
	// �������� ���������� 
	class animal {
	public:
		// �������������, ���������� � ���� ������ �� ����-��
		int age = 0; 
		char name[20];
    static  animal* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;  // ����
		virtual void Out(ofstream &ofst) = 0;     // �����
		bool Compare(animal &other);
		virtual int LenghtName() = 0;
    virtual void OnlyFish(ofstream &ofst);
	};
} // end simple_animals namespace
#endif

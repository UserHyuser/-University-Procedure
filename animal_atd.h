#ifndef __animal_atd__
#define __animal_atd__
// ����������� ����������� ����� ������
#include "bird_atd.h"
#include "fish_atd.h"
namespace simple_animals {
  // ���������, ���������� ��� ��������� ������
  struct animal {
    // �������� ������ ��� ������ �� �����
    enum key {BIRD, FISH};
    key k; // ����
	char name[20];
	int age = 0;
    // ������������ ������������
    union { // ���������� ���������
      bird r;
      fish t;
    };
  };
} // end simple_animals namespace
#endif

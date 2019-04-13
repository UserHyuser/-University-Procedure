#include "CppUnitTest.h"
#include <fstream>
#include "../1 laba - m/conteiner_atd.h"
#include "../1 laba - m//animal_atd.h"
#include "../1 laba - m/beast_atd.h"
#include "../1 laba - m/bird_atd.h"
#include "../1 laba - m/fish_atd.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace simple_animals;

namespace simple_animals
{
	//Сигнатуры используемых внешних функций
	void Init(container &c);//вспомогательная
	//void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void OnlyFish(container &c, ofstream &ofst);
	void Sort(container &c);

	animal *In(ifstream &ifdt); 
	int LenghtName(animal &s); 
	void Out(animal &s, ofstream &ofst);
	//bool Compare(animal *first, animal *second);

	void In(beast &b, ifstream &ist);
	void In(bird &r, ifstream &ist);
	void In(fish  &t, ifstream &ist);
	void Out(bird &r, char name[20], int age, ofstream &ofst);
	void Out(fish  &t, char name[20], int age, ofstream &ofst);
	void Out(beast &b, char name[20], int age, ofstream &ofst);

}

		
TEST_CLASS(In_lower)
{
public:
		
	TEST_METHOD(Beast)
	{
		ifstream ifst("../UnitTest/TestFiles/In_lower_beast.txt");
		beast myBeast;
		In(myBeast, ifst);

		int expected = 2;
		int actual = myBeast.eat;
		
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Bird)
	{
		ifstream ifst("../UnitTest/TestFiles/In_lower_bird.txt");
		bird myBird;
		In(myBird, ifst);

		int expected = 1;
		int actual = myBird.fly;

		Assert::AreEqual(expected, actual);
	}
	

	TEST_METHOD(Fish)
	{
		ifstream ifst("../UnitTest/TestFiles/In_lower_fish.txt");
		fish myFish;
		In(myFish, ifst);

		int expected = 1;
		int actual = myFish.place;

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(In_middle)
{
public:
	TEST_METHOD(test_name)
	{
		animal* testAnimal;
		ifstream ifst("../UnitTest/TestFiles/In_middle_beast.txt");
		testAnimal = In(ifst);

		string expected = "TestName";
		string actual = testAnimal->name;
		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++) {
			if (actual[i] != expected[i])
				checkFlag = false;
		}
		Assert::AreEqual(true, checkFlag);
	}

	TEST_METHOD(test_key)
	{
		animal* testAnimal;
		ifstream ifst("../UnitTest/TestFiles/In_middle_beast.txt");
		testAnimal = In(ifst);

		int expected = animal::key::BEAST;
		int actual = testAnimal->k;
		
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(test_age_beast)
	{
		animal* testAnimal;
		ifstream ifst("../UnitTest/TestFiles/In_middle_beast.txt");
		testAnimal = In(ifst);

		int expected = 5;
		int actual = testAnimal->age;

		Assert::AreEqual(expected, actual);
	}
	

	TEST_METHOD(test_eat)
	{
		animal* testAnimal;
		ifstream ifst("../UnitTest/TestFiles/In_middle_beast.txt");
		testAnimal = In(ifst);

		int expected = 2;
		int actual = testAnimal->b.eat;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(test_age_bird)
	{
		animal* testAnimal;
		ifstream ifst("../UnitTest/TestFiles/In_middle_bird.txt");
		testAnimal = In(ifst);

		int expected = 5;
		int actual = testAnimal->age;

		Assert::AreEqual(expected, actual);
	}
	TEST_METHOD(test_age_fish)
	{
		animal* testAnimal;
		ifstream ifst("../UnitTest/TestFiles/In_middle_fish.txt");
		testAnimal = In(ifst);

		int expected = 7;
		int actual = testAnimal->age;

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(IТ_OUT_higher)
{
public:

	TEST_METHOD(IN_Test_cont_len)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../UnitTest/TestFiles/In_higher_1.txt");
		In(testing_cont, test_file_in);

		int actual = testing_cont.len;
		int expected = 3;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(IN_OUT_Test_cont)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../UnitTest/TestFiles/In_higher_1.txt");//входной
		In(testing_cont, test_file_in);
		ofstream test_file_out("../UnitTest/TestFiles/In_higher_2.txt");//выходной
		Out(testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest/TestFiles/In_higher_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest/TestFiles/In_higher_3.txt", "r");//эталон
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(Out_lower)
{
public:

	TEST_METHOD(Test1_bird)
	{
		bird testing_type;
		testing_type.fly = 1;
		ofstream test_file_out("../UnitTest/TestFiles/Out_lower_bird.txt");
		Out(testing_type, "Орел", 3, test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest/TestFiles/Out_lower_bird.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Это перелетная птица Орел возраст:3";

		Assert::AreEqual(expected, actual);
	}
	
	TEST_METHOD(Test2_fish)
	{
		fish testing_type;
		testing_type.place = 1;
		ofstream test_file_out("../UnitTest/TestFiles/Out_lower_fish.txt");
		Out(testing_type, "Пила", 3, test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest/TestFiles/Out_lower_fish.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Fish Пила lives in sea:3";

		Assert::AreEqual(expected, actual);
	}
	
	TEST_METHOD(Test3_beast)
	{
		beast testing_type;
		testing_type.eat = 1;
		ofstream test_file_out("../UnitTest/TestFiles/Out_lower_beast.txt");
		Out(testing_type, "Волк", 3, test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest/TestFiles/Out_lower_beast.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Это травоядный зверь Волк возраст:3";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(Out_middle)
{
public:

	TEST_METHOD(Beast)
	{
		animal* testing_type = new animal;
		testing_type->k = testing_type->BEAST;
		char tmp_mes[20] = "Волк";
		strcpy(testing_type->name, tmp_mes);
		testing_type->b.eat = 0;
		ofstream test_file_out("../UnitTest/TestFiles/Out_middle_beast.txt");
		Out(testing_type[0], test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest/TestFiles/Out_middle_beast.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Это хищный зверь Волк возраст:0";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Sort)
{
public:

	TEST_METHOD(Test_sort_IN_OUT)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../UnitTest/TestFiles/In_higher_1.txt");//вход
		In(testing_cont, test_file_in);
		Sort(testing_cont);
		ofstream test_file_out("../UnitTest/TestFiles/Sort_2.txt");//выход
		Out(testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest/TestFiles/Sort_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest/TestFiles/Sort_3.txt", "r");//эталон
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Filter)
{
public:

	TEST_METHOD(Test_filter_IN_OUT)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../UnitTest/TestFiles/In_higher_1.txt");
		In(testing_cont, test_file_in);
		ofstream test_file_out("../UnitTest/TestFiles/Filter_2.txt");
		OnlyFish(testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest/TestFiles/Filter_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest/TestFiles/Filter_3.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(LengthName_func)
{
public:

	TEST_METHOD(Test1)
	{
		animal s;
		char testName[20] = "Волк";
		for (int i = 0; i < 20; i++)
			s.name[i] = testName[i];
		int actual = LenghtName(s);

		Assert::AreEqual(4, actual);
	}

	TEST_METHOD(Test2)
	{
		animal s;
		char testName[20] = "";
		for (int i = 0; i < 20; i++)
			s.name[i] = testName[i];
		int actual = LenghtName(s);

		Assert::AreEqual(0, actual);
	}

	TEST_METHOD(Test3)
	{
		animal s;
		char testName[30] = "Волкииииииииииииииии";
		for (int i = 0; i < 20; i++)
			s.name[i] = testName[i];
		int actual = LenghtName(s);

		Assert::AreEqual(20, actual);
	}
};
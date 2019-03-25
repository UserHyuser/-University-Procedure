#include "fish_atd.h"
using namespace std;
namespace simple_animals {
	// Ââîä ïàðàìåòðîâ øàðà
	void fish::InData(ifstream &ifst)
	{
		ifst >> place;
		ifst >> name;
		ifst >> age;
	}
} // end simple_animals namespace

using namespace std;
namespace simple_animals {
	// Âûâîä ïàðàìåòðîâ 
	void fish::Out(ofstream &ofst)
	{
		if (place == 0) {
			ofst << "Fish " << name << " живет в озере"
				<< " возраст: " << age << endl;
		}
		else if (place == 1) {
			ofst << "Рыба " << name << " живет в море"
				<< " возраст: " << age << endl;
		}
		else if (place == 2) {
			ofst << "Рыба " << name << " живет в реке"
				<< " возраст: " << age << endl;
		}
	}

	void fish::OnlyFish(ofstream &ofst) {
		Out(ofst);
	}

	int fish::LenghtName() {
		int arrayLength = 0;
		for (int i = 0; name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}

} // end simple_animals namespace

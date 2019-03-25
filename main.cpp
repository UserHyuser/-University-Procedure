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

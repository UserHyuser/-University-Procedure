#ifndef __conteiner__
#define __conteiner__
namespace simple_animals {
// —сылка на описание геометрической фигуры. 
// «нание структуры самой фигуры дл€ представленной 
// реализации контейнера не требуетс€
struct animal;
// ѕростейший контейнер на основе одномерного массива
  struct container
  {
    //const int max_len=100; //максимальна€ длина
	enum {max_len = 100};
    int len; // текуща€ длина
    animal *cont[max_len];
  };
}
#endif
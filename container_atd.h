#ifndef __container_atd__
#define __container_atd__
namespace simple_animals {
	// Signature of using struct
	// Knowledge of the structure is not required for the presented container implementations 
	struct animal;
	// Simple container using one-dimensional massive
	struct container
	{
		//Contaier's maximal length
		enum { max_len = 100 };
		int len; // Current length
		animal *cont[max_len];
	};
}
#endif
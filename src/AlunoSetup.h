#ifndef __ALUNOSETUP_H__
#define __ALUNOSETUP_H__

#include <vector>
#include "AlunoCarro1.h"

using std::vector;

/*
* Nesse método, retorne um vector com todos os carros que serão desenhados no exercício.
*/
vector<Car*> createCars()
{
	vector<Car*> cars;
	cars.push_back(new AlunoCarro1());	
	return cars;
}

#endif //__ALUNOSETUP_H__
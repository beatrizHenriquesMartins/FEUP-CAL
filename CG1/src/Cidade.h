/*
 * Cidade.h
 *
 *  Created on: 31/03/2017
 *      Author: JAlmeida
 */

#ifndef SRC_CIDADE_H_
#define SRC_CIDADE_H_

#include <string>
#include "Coordenadas.h"

using namespace std;

class Cidade {
	string nome;
	Coordenadas coordenadas;
public:
	Cidade();
	Cidade(string nome, Coordenadas coordenadas);
	virtual ~Cidade();
};



#endif /* CIDADE_H_ */

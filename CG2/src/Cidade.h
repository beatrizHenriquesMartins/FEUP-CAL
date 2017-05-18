/*
 * Cidade.h
 *
 *  Created on: 31/03/2017
 *      Author: JAlmeida
 */

#ifndef SRC_CIDADE_H_
#define SRC_CIDADE_H_

#include <string>
#include <vector>
#include "Coordenadas.h"

using namespace std;

class Cidade {
	int id;
	string nome;
	Coordenadas coordenadas;
	vector<int> ligados;
    vector<string> monumentos;
public:
	Cidade();
	Cidade(int id, string nome, Coordenadas coordenadas);
	virtual ~Cidade();

	string getNome() const;

	Coordenadas getCoordenadas() const;

	vector<int> getLigados() const;

	void setId(int id);
	int getId();

	friend bool operator==(Cidade&a, const Cidade &rhs);

	void setNome(string nome);

	void setCoordenadas(Coordenadas coordenadas);

	void setLigados(vector<int> ligados);
    
    void setMonumentos(vector<string> monumentos);
    
    vector<string> getMonumentos() const;

	bool friend  operator!=(Cidade&a, const Cidade &rhs);
};





#endif /* CIDADE_H_ */

/*
 * Viagem.h
 *
 *  Created on: 26/03/2017
 *      Author: beatrizHm
 */

#ifndef SRC_VIAGEM_H_
#define SRC_VIAGEM_H_

#include <vector>
#include "Transporte.h"
#include "Estadia.h"
#include "Data.h"

#define NULL 0

enum periodo { nonDEFINED,  epocaBAIXA, epocaMEDIA, epocaALTA };



class Viagem {
	Data ida;
	Data volta;
	Transporte transporte;
	vector<Estadia> estadia;
	periodo epoca;
	double custo; //peso
	double distancia; //peso

public:
	Viagem();


	Viagem(Data ida);
	Viagem(Data ida, Data volta);


	Viagem(Data ida, double custo, double distancia);
	Viagem(Data ida, Data volta, double custo, double distancia);

	Viagem(Data ida, Data volta, Transporte T);


	

	bool checkEpocaAlta(Data dia);
	bool checkEpocaBaixa(Data dia);
	bool checkEpocaMedia(Data dia);

	double getCusto() const;
	double getDistancia() const;
	Transporte getMeiosTransporte() const;

	void setCusto(double custo);
	void setDistancia(double distancia);
	void addTransporte(Transporte T);
	void setPeriodo(periodo epoca);
	periodo getPeriodo();
};

#endif /* SRC_VIAGEM_H_ */

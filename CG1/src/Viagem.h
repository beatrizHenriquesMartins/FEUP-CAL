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
	vector<Transporte> transporte;
	vector<Estadia> estadia;
	periodo epoca;

public:
	Viagem();

	Viagem(Data ida);
	Viagem(Data ida, Data volta);

	bool checkEpocaAlta(Data dia);
	bool checkEpocaBaixa(Data dia);
	bool checkEpocaMedia(Data dia);


	periodo getPeriodoIda(Data ida);
	periodo getPeriodoIdaVolta(Data ida, Data volta);
};

#endif /* SRC_VIAGEM_H_ */

/*
 * Viagem.cpp
 *
 *  Created on: 26/03/2017
 *      Author: beatrizHm
 */

#include "Viagem.h"

Viagem::Viagem() {
	this->ida = Data();
	this->volta = Data();
	this->transporte = {};
	this->estadia = {};
	epoca = static_cast<periodo>(0);
}

Viagem::Viagem(Data ida) {
	this->ida = ida;
	this->volta = Data();
	epoca = getPeriodoIda(ida);

	//this->transporte  = {}; por fazer
	//this->estadia = {}; por fazer
}

bool Viagem::checkEpocaAlta(Data dia) {

	if (dia.getMes() == 1 && dia.getDia() == 1)
		return true; // ano novo
	if (dia.getMes() == 4) {
		if (10 <= dia.getDia() <= 19)
			return true;
	} // pascoa 2017
	else if (dia.getMes() == 7 || dia.getMes() == 8)
		return true; // meses de julho e agosto
	else if (dia.getMes() == 12) {
		if ( 15 <= dia.getDia() <= 31)
			return true; // natal  ano novo
	}
	return false;
}

bool Viagem::checkEpocaBaixa(Data dia) {

	if (!checkEpocaMedia(dia) && !(checkEpocaAlta(dia))) return true;
	// resto do ano

	return false;

}

bool Viagem::checkEpocaMedia(Data dia) {
	if (dia.getMes() == 9 || dia.getMes() == 6 || dia.getMes() == 11) return true;
	 //meses de setembro, junho e novembro
}

periodo Viagem::getPeriodoIda(Data ida) {

	if (checkEpocaAlta(ida)) return static_cast<periodo>(3);
	else if(checkEpocaMedia(ida)) return static_cast<periodo>(2);
	else if(checkEpocaBaixa(ida)) return static_cast<periodo>(1);
	else return static_cast<periodo>(0);

}

periodo Viagem::getPeriodoIdaVolta(Data ida, Data volta) {

	if (checkEpocaAlta(ida) || checkEpocaAlta(volta)) return static_cast<periodo>(3);
	else if (checkEpocaMedia(ida) || checkEpocaMedia(volta)) return static_cast<periodo>(2);
	else if (checkEpocaBaixa(ida) || checkEpocaBaixa(volta)) return static_cast<periodo>(1);
	else return static_cast<periodo>(0);
}


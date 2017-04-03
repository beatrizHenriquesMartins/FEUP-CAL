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
		if (10 < dia.getDia() < 19)
			return true;
	} // pascoa 2017
	else if (dia.getMes() == 7 || dia.getMes() == 8)
		return true; // meses de julho e agosto
	else if (dia.getMes() == 12) {
		if (dia.getDia() == 31 || dia.getDia() == 25)
			return true; // natal e ano novo
	}
	return false;
}
bool Viagem::checkEpocaBaixa(Data dia) {
}

periodo Viagem::getPeriodoIda(Data ida) {

}

periodo Viagem::getPeriodoIdaVolta(Data ida, Data volta) {

	if (ida.getMes() == 7 || ida.getMes() == 8)

		if (ida.getDia() == 31 && ida.getMes() == 12)
			return static_cast<periodo>(0);
	if (volta.getDia() == 31 && volta.getMes() == 12)
		return static_cast<periodo>(0);

	// se a viagem de ida ou volta calham no dia de natal, EPOCA ALTA
	if (ida.getDia() == 25 && ida.getMes() == 12)
		return static_cast<periodo>(0);
	if (volta.getDia() == 25 && volta.getMes() == 12)
		return static_cast<periodo>(0);

}


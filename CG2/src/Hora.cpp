/*
 * Hora.cpp
 *
 *  Created on: 04/04/2017
 *      Author: beatrizHm
 */

#include "Hora.h"

Hora::Hora() {

}

Hora::Hora(int hora, int minutos) {
	this->hora = hora;
	this->minutos = minutos;
}

int Hora::getHora() const {
	return hora;
}

int Hora::getMinutos() const {
	return minutos;
}

void Hora::setHora(int hora) {
	this->hora = hora;
}

void Hora::setMinutos(int minutos) {
	this->minutos = minutos;
}

string Hora::toString() {

	stringstream ss;

	if (hora < 10 && this->minutos < 10) {
		ss << "0" << this->hora << ":" << "0" << this->minutos;
		return ss.str();
	} else if (hora >= 10 && this->minutos < 10) {
		ss << this->hora << ":" << "0" << this->minutos;
		return ss.str();
	} else if (hora >= 10 && this->minutos >= 10) {
		ss << this->hora << ":" << this->minutos;
		return ss.str();
	} else if (hora < 10 && this->minutos >= 10) {
		ss << "0" << this->hora << ":" << this->minutos;
		return ss.str();
	}
}

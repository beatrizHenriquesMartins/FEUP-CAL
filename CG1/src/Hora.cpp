/*
 * Hora.cpp
 *
 *  Created on: 04/04/2017
 *      Author: beatrizHm
 */

#include "Hora.h"

Hora::Hora() {
	// TODO Auto-generated constructor stub

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

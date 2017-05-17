/*
 * Data.cpp
 *
 *  Created on: 24/03/2017
 *      Author: beatrizHm
 */

#include "Data.h"

Data::Data() {
		this->dia = 0;
		this->mes = 0;
		this->ano = 0;
}

Data::Data(int dia, int mes, int ano) {
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

int Data::getDia() const {
	return this->dia;
}

int Data::getMes() const {
	return this->mes;
}

int Data::getAno() const {
	return this->ano;
}

void Data::setDia(int dia) {
	this->dia = dia;
}

void Data::setMes(int mes) {
	this->mes = mes;
}

void Data::setAno(int ano) {
	this->ano = ano;
}

string Data::toString() {
	stringstream ss;

	ss << this->dia << "/" << this->mes << "/" << this->ano;

	return ss.str();
}

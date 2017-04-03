/*
 * Transporte.cpp
 *
 *  Created on: 24/03/2017
 *      Author: beatrizHm
 */

#include "Transporte.h"

Transporte::Transporte(tipoTransporte meio, float preco, Data data, int numLugares) {
	this->preco = preco;
	this->data = data;
	this->numLugares = numLugares;
	this->numLugaresOcupados = 0;
	this->meioTransporte = meio;
}

float Transporte::getPreco() const {
	return this->preco;
}

tipoTransporte Transporte::getTipo() const {
	return this->meioTransporte;
}

Data Transporte::getData() const {
	return this->data;
}

void Transporte::setPreco(float preco) {
	this->preco = preco;
}

void Transporte::setTipo(tipoTransporte meioTransporte) {
	this->meioTransporte = meioTransporte;
}

void Transporte::setData(Data data) {
	this->data = data;
}

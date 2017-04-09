/*
 * Transporte.cpp
 *
 *  Created on: 24/03/2017
 *      Author: beatrizHm
 */

#include "Transporte.h"

Transporte::Transporte(tipoTransporte meio, Hora horaPartida) {
	this->meioTransporte = meio;
	this->horaPartida = horaPartida;
	
}

float Transporte::getPreco() const {
	return this->preco;
}



tipoTransporte Transporte::getTipo() const {
	return this->meioTransporte;
}



Hora Transporte::getHoraPartida() const {
	return horaPartida;
}

void Transporte::setPreco(float preco) {
	this->preco = preco;
}

void Transporte::setDuracao(Hora hora)
{
	this->duracao = hora;
}



void Transporte::setTipo(tipoTransporte meioTransporte) {
	this->meioTransporte = meioTransporte;
}





void Transporte::setHoraPartida(Hora horaPartida) {
	this->horaPartida = horaPartida;
}

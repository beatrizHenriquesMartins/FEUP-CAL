/*
 * Transporte.cpp
 *
 *  Created on: 24/03/2017
 *      Author: beatrizHm
 */

#include "Transporte.h"

Transporte::Transporte(tipoTransporte meio, string origem, string destino,
		Data data, Hora horaPartida, float preco, int numLugares) {
	this->meioTransporte = meio;
	this->origem = origem;
	this->destino = destino;
	this->data = data;
	this->horaPartida = horaPartida;
	this->preco = preco;
	this->numLugares = numLugares;
	this->numLugaresOcupados = 0;
}

float Transporte::getPreco() const {
	return this->preco;
}

int Transporte::getDistancia() const {
	return this->distancia;
}

Data Transporte::getData() const {
	return this->data;
}

int Transporte::getNumLugaresOcupados() const {
	return this->numLugaresOcupados;
}

int Transporte::getNumLugares() const {
	return this->numLugares;
}

tipoTransporte Transporte::getTipo() const {
	return this->meioTransporte;
}

string Transporte::getOrigem() const {
	return this->origem;
}

string Transporte::getDestino() const {
	return this->destino;
}

Hora Transporte::getHoraPartida() const {
	return horaPartida;
}

void Transporte::setPreco(float preco) {
	this->preco = preco;
}

void Transporte::setDistancia(int distancia) {
	this->distancia = distancia;
}

void Transporte::setData(Data data) {
	this->data = data;
}

void Transporte::setNumLugaresOcupados(int numLugaresOcupados) {
	this->numLugaresOcupados = numLugaresOcupados;
}

void Transporte::setNumLugares(int numLugares) {
	this->numLugares = numLugares;
}

void Transporte::setTipo(tipoTransporte meioTransporte) {
	this->meioTransporte = meioTransporte;
}

void Transporte::setOrigem(string origem) {
	this->origem = origem;
}

void Transporte::setDestino(string destino) {
	this->destino = destino;
}

void Transporte::setHoraPartida(Hora horaPartida) {
	this->horaPartida = horaPartida;
}

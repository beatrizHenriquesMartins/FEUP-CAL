/*
 * Cidade.cpp
 *
 *  Created on: 31/03/2017
 *      Author: up201504874
 */

#include "Cidade.h"

using namespace std;

Cidade::Cidade() {
	this->nome = "";
	this->coordenadas = Coordenadas();

}

Cidade::Cidade(string nome, Coordenadas coordenadas) {
	this->nome = nome;
	this->coordenadas = coordenadas;

}

Cidade::~Cidade() {

}

string Cidade::getNome() const {
	return nome;
}

Coordenadas Cidade::getCoordenadas() const {
	return coordenadas;
}

vector<int> Cidade::getLigados() const {
	return ligados;
}


void Cidade::setNome(string nome) {
	this->nome = nome;
}

void Cidade::setCoordenadas(Coordenadas coordenadas) {
	this->coordenadas = coordenadas;
}

void Cidade::setLigados(vector<int> ligados) {
	this->ligados = ligados;
}

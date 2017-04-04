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

Cidade::Cidade(int id, string nome, Coordenadas coordenadas) {
	this->id = id;
	this->nome = nome;
	this->coordenadas = coordenadas;

}

Cidade::~Cidade() {
	// TODO Auto-generated destructor stub

} /* namespace std */

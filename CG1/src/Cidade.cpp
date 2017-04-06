/*
 * Cidade.cpp
 *
 *  Created on: 31/03/2017
 *      Author: up201504874
 */

#include "Cidade.h"



using namespace std;

unsigned int Cidade::idstatic = 1;


Cidade::Cidade() {
	this->nome = "";
	this->coordenadas = Coordenadas();

}

Cidade::Cidade(int id, string nome, Coordenadas coordenadas) {
	this->id = idstatic;
	this->nome = nome;
	this->coordenadas = coordenadas;
	idstatic++;

}

Cidade::~Cidade() {

}

void Cidade::setId(int id) {
	this->id = id;
}

int Cidade::getId() {
	return this->id;
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

bool operator==(Cidade&a, const Cidade &rhs) {
	Cidade estacao = rhs;
	if (a.getId() == estacao.getId()) return true;
	else return false;
}
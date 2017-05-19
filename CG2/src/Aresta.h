#pragma once

#ifndef SRC_ARESTA_H_
#define SRC_ARESTA_H_

#include <string>

using namespace std;

class Aresta
{
	int id;
	int origem;
	int destino;
	string tipoTransporte;

public:
	Aresta(int id, int cidadeOrigem, int cidadeDestino, string transporte) {
		this->id = id;
		this->origem = cidadeOrigem;
		this->destino = cidadeDestino;
		this->tipoTransporte = transporte;
	}

	int getId() {
		return this->id;
	}

	int getIdOrigem() {
		return this->origem;
	}
	
	int getIdDestino() {
		return this->destino;
	}

	string getTipoTransporte() {
		return this->tipoTransporte;
	}

	void setId(int id) {
		this->id = id;
	}

	void setidOrigem(int id) {
		this->origem = id;
	}

	void setIdDestino(int id) {
		this->destino = id;
	}

	void setTipoTransporte(string transporte) {
		this->tipoTransporte = transporte;
	}

};

#endif


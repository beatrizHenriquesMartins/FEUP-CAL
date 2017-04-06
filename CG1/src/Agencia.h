/*
 * menu.h
 *
 *  Created on: 26/03/2017
 *      Author: beatrizHm
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Cliente.h"
#include "Viagem.h"
#include "Transporte.h"
#include "Cidade.h"

#include "Graph.h"
#include "graphviewer.h"
#include "DadosGraph.h"

#define MAP_TO_METERS 32
#define VEL_MED_AVIAO 890


class Agencia {
	vector<Cliente*> clientes;
public:
	void lerFicheiroClientes();
	void lerFicheiroAvioes();
	void escreverFicheiroClientes();
	void escreverFicheiroAvioes();
	void trim(string &str);
	Agencia();
	vector<Cliente*> getClientes() const;
	void setClientes(vector<Cliente*> clientes);
	void menuInicial();
	void menuNovoCliente();
	void menuListaClientes();
	void menuProcuraClientes();
	int	menuNovaViagem();
	void novaViagem();
	void menuListaDestinos();
	int procuraCliente(unsigned long nif);
	int lengthNumber(int n);


	void carregarGrafo(int choice);

};

#endif /* SRC_MENU_H_ */

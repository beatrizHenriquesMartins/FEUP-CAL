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

class Menu {
	vector<Cliente*> clientes;
public:
	void lerFicheiroClientes();

	void escreverFicheiroClientes();

	void trim(string &str);

	Menu();

	vector<Cliente*> getClientes() const;

	void setClientes(vector<Cliente*> clientes);

	void menuInicial();

	void menuNovoCliente();

	void menuListaClientes();

	void menuProcuraClientes();

	void menuNovaViagem();

	void menuListaDestinos();

	int procuraCliente(unsigned long nif);

	int lengthNumber(int n);
};

#endif /* SRC_MENU_H_ */

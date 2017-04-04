/*
 * Transporte.h
 *
 *  Created on: 24/03/2017
 *      Author: beatrizHm
 */

#ifndef SRC_TRANSPORTE_H_
#define SRC_TRANSPORTE_H_

#include <string>
#include "Data.h"

using namespace std;

enum tipoTransporte {
	AVIAO
};

/*, BARCO - para já fica só o avião para simplificar*/

class Transporte {
	float preco;
	int distancia;
	Data data;
	int numLugaresOcupados;
	int numLugares;
	tipoTransporte meioTransporte;

public:

	/**
	 * @brief Construtor de Transporte
	 * @param float preco - preço do transporte
	 * @param tipoTransporte tipo - tipo de transporte
	 * @param Data data - data da viagem
	 * @param int numLugares - número de lugares disponíveis
	 */
	Transporte(tipoTransporte meio, float preco, Data data, int numLugares);

	/**
	 * @brief Funcao de retorno do preco do Transporte
	 * @return float preço
	 */
	float getPreco() const;

	/**
	 * @brief Funcao de retorno de tipo do Transporte
	 * @return string tipo
	 */
	tipoTransporte getTipo() const;

	/**
	 * @brief Funcao de retorno da data do Transporte
	 * @return Data data
	 */
	Data getData() const;

	/**
	 * @brief Funcao modificadora do preço do transporte
	 * @param float Preço
	 */
	void setPreco(float preco);

	/**
	 * @brief Funcao modificadora do tipo do transporte
	 * @param string tipo
	 */
	void setTipo(tipoTransporte meioTransporte);

	/**
	 * @brief Funcao modificadora da data do transporte
	 * @param Data data
	 */
	void setData(Data data);
};

#endif /* SRC_TRANSPORTE_H_ */

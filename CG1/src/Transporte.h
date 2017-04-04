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
#include "Hora.h"

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
	string origem;
	string destino;
	Hora horaPartida;
public:

	/**
	 * @brief Construtor de Transporte
	 * @param tipoTransporte tipo - tipo de transporte
	 * @param string origem - nome origem (lugar de partida)
	 * @param string destino - nome destino (lugar de chegada)
	 * @param Data data - data da viagem
	 * @param float preco - preço do transporte
	 * @param int numLugares - número de lugares disponíveis
	 * @param Hora horaPartida - hora de partida (hh:mm)
	 */
	Transporte(tipoTransporte meio, string origem, string destino, Data data,
			Hora horaPartida, float preco, int numLugares);

	/**
	 * @brief Funcao de retorno do preco do Transporte
	 * @return float preço
	 */
	float getPreco() const;

	/**
	 * @brief Funcao de retorno da distancia da origem ao destino
	 * @return int distancia
	 */
	int getDistancia() const;

	/**
	 * @brief Funcao de retorno da data do Transporte
	 * @return Data data
	 */
	Data getData() const;

	/**
	 * @brief Funcao de retorno para numero de lugares ocupados do Transporte
	 * @return int numLugaresOcupados
	 */
	int getNumLugaresOcupados() const;

	/**
	 * @brief Funcao de retorno de lugares no transporte
	 * @return int numLugares
	 */
	int getNumLugares() const;

	/**
	 * @brief Funcao de retorno de tipo do Transporte
	 * @return string tipo
	 */
	tipoTransporte getTipo() const;

	/**
	 * @brief Funcao de retorno da origem do Transporte
	 * @return string origem
	 */
	string getOrigem() const;

	/**
	 * @brief Funcao de retorno da destino do Transporte
	 * @return string destino
	 */
	string getDestino() const;

	/**
	 * @brief Funcao de retorno da hora de partida do Transporte
	 * @return Hora hora
	 */
	Hora getHoraPartida() const;

	/**
	 * @brief Funcao modificadora do preço do transporte
	 * @param float Preço
	 */
	void setPreco(float preco);

	/**
	 * @brief Funcao modificadora da distancia da origem ao destino do transporte
	 * @param int distancia
	 */
	void setDistancia(int distancia);

	/**
	 * @brief Funcao modificadora da data do transporte
	 * @param Data data
	 */
	void setData(Data data);

	/**
	 * @brief Funcao modificadora do numero de lugares ocupados do transporte
	 * @param int numLugaresOcupados
	 */
	void setNumLugaresOcupados(int numLugaresOcupados);

	/**
	 * @brief Funcao modificadora do numero de lugares do transporte
	 * @param int numLugares
	 */
	void setNumLugares(int numLugares);

	/**
	 * @brief Funcao modificadora do tipo do transporte
	 * @param string tipo
	 */
	void setTipo(tipoTransporte meioTransporte);

	/**
	 * @brief Funcao modificadora da origem do transporte
	 * @param string Origem
	 */
	void setOrigem(string origem);

	/**
	 * @brief Funcao modificadora do destino do transporte
	 * @param string destino
	 */
	void setDestino(string destino);

	/**
	 * @brief Funcao modificadora da hora de partida do transporte
	 * @param Hora horaPartida
	 */
	void setHoraPartida(Hora horaPartida);

};

#endif /* SRC_TRANSPORTE_H_ */

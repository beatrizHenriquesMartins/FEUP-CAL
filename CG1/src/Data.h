/*
 * Data.h
 *
 *  Created on: 24/03/2017
 *      Author: beatrizHm
 */

#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include <string>
#include <sstream>

using namespace std;

class Data {
	int dia;
	int mes;
	int ano;
public:

	/**
	* @brief Construtor de Data vazio
	*/
	Data();

	/**
	* @brief Construtor de Data
	* @param int dia - dia
	* @param int mes - mes
	* @param int ano - ano
	*/
	Data(int dia, int mes, int ano);

	/**
	* @brief Função de retorno para dia
	* @return int dia
	*/
	int getDia() const;

	/**
	* @brief Função de retorno para mes
	* @return int mes
	*/
	int getMes() const;

	/**
	* @brief Função de retorno para ano
	* @return int ano
	*/
	int getAno() const;

	/**
	* @brief Função de modificação de dia
	* @param int dia
	*/
	void setDia(int dia);

	/**
	* @brief Função de modificação de mes
	* @param int mes
	*/
	void setMes(int mes);

	/**
	* @brief Função de modificação de ano
	* @param int ano
	*/
	void setAno(int ano);

	/**
	* @brief Função de escrita formatada de Data
	* @return string data no formato dd/mm/aa
	*/
	string toString();

};

#endif /* SRC_DATA_H_ */

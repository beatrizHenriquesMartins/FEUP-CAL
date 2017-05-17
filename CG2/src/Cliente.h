/*
 * Cliente.h
 *
 *  Created on: 23/03/2017
 *      Author: beatrizHm
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>

#include "Viagem.h"

using namespace std;

class Cliente {
	static int ultId;
	int id;
	string nome;
	unsigned long numTelefone;
	unsigned long long ss; //seguranca social
	unsigned long nif;
	string morada;
	string email;

public:

	/**
	 * @brief Construtor de Cliente
	 * @param string nome - nome
	 * @param unsigned long numTelefone - numero de Telefone
	 * @param unsigned long ss - seguranca social
	 * @param unsigned long nif - numero de contribuinte
	 * @param string morada - morada
	 * @param string email - email
	 */
	Cliente(string nome, unsigned long numTelefone, unsigned long long ss,
			unsigned long nif, string morada, string email);

	/**
	 * @brief Construtor de Cliente
	 * @param int id - número identificador
	 * @param string nome - nome
	 * @param unsigned long numTelefone - número de Telefone
	 * @param unsigned long ss - segurança social
	 * @param unsigned long nif - número de contribuinte
	 * @param string morada - morada
	 * @param string email - email
	 */
	Cliente(int id, string nome, unsigned long numTelefone, unsigned long long ss,
			unsigned long nif, string morada, string email);

	/**
	 * @brief Funcao de retorno para id do cliente
	 * @return int id
	 */
	int getID() const;

	/**
	 * @brief Funcao de retorno para nome do cliente
	 * @return string nome
	 */
	string getNome() const;

	/**
	 * @brief Funcao de retorno para numero de Telefone do cliente
	 * @return unsigned long numero de telefone
	 */
	unsigned long getNumTelefone() const;

	/**
	 * @brief Funcao de retorno para seguranca social do cliente
	 * @return unsigned long seguranca social
	 */
	unsigned long long getSs() const;

	/**
	 * @brief Funcao de retorno para contribuinte do cliente
	 * @return unsigned long contribuinte
	 */
	unsigned long getNif() const;

	/**
	 * @brief Funcao de retorno para morada do cliente
	 * @return string morada
	 */
	string getMorada() const;

	/**
	 * @brief Funcao de retorno para email do cliente
	 * @return string email
	 */
	string getEmail() const;

	/**
	 * @brief Funcao modificadora para nome do Cliente
	 * @param string nome
	 */
	void setNome(string nome);

	/**
	 * @brief Funcao modificadora para numero de Telefone do Cliente
	 * @param unsigned long numero de telefone
	 */
	void setNumTelefone(unsigned long numTelefone);

	/**
	 * @brief Funcao modificadora para seguranca social do Cliente
	 * @param unsigned long seguranca social
	 */
	void setSs(unsigned long long ss);

	/**
	 * @brief Funcao modificadora para contribuinte do Cliente
	 * @param unsigned long contribuinte
	 */
	void setNif(unsigned long nif);

	/**
	 * @brief Funcao modificadora para morada do Cliente
	 * @param string morada
	 */
	void setMorada(string morada);

	/**
	 * @brief Funcao modificadora para email do Cliente
	 * @param string email
	 */
	void setEmail(string email);

};

#endif /* CLIENTE_H_ */

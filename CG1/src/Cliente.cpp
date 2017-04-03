/*
 * Cliente.cpp
 *
 *  Created on: 23/03/2017
 *      Author: beatrizHm
 */

#include "Cliente.h"

int Cliente::ultId = 1;

Cliente::Cliente(string nome, unsigned long numTelefone, unsigned long ss,
		unsigned long nif, string morada, string email) {

	this->id = ultId++;
	this->nome = nome;
	this->numTelefone = numTelefone;
	this->ss = ss;
	this->nif = nif;
	this->morada = morada;
	this->email = email;

}

Cliente::Cliente(int id, string nome, unsigned long numTelefone,
		unsigned long ss, unsigned long nif, string morada, string email) {
	this->id = id;
	this->nome = nome;
	this->numTelefone = numTelefone;
	this->ss = ss;
	this->nif = nif;
	this->morada = morada;
	this->email = email;
	ultId = ++id;
}

int Cliente::getID() const {
	return this->id;
}

string Cliente::getNome() const {
	return this->nome;
}

unsigned long Cliente::getNumTelefone() const {
	return this->numTelefone;
}

unsigned long Cliente::getSs() const {
	return this->ss;
}

unsigned long Cliente::getNif() const {
	return nif;
}

string Cliente::getMorada() const {
	return morada;
}

string Cliente::getEmail() const {
	return email;
}

void Cliente::setNome(string nome) {
	this->nome = nome;
}

void Cliente::setNumTelefone(unsigned long numTelefone) {
	this->numTelefone = numTelefone;
}

void Cliente::setSs(unsigned long ss) {
	this->ss = ss;
}

void Cliente::setNif(unsigned long nif) {
	this->nif = nif;
}

void Cliente::setMorada(string morada) {
	this->morada = morada;
}

void Cliente::setEmail(string email) {
	this->email = email;
}

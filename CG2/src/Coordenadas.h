/*
 * Coordenadas.h
 *
 *  Created on: 31/03/2017
 *      Author: JAlmeida
 */

#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenadas {
	int x;
	int y;

public:
	/**
	 * @brief Construtor de Coordenadas
	 * @param int x - coordenada x
	 * @param int y  - coordenada y
	 */
	Coordenadas(int x, int y) {
		this->x = x;
		this->y = y;
	}

	/**
	 * @brief Construtor default de Coordenadas
	 * @param int x - inicializada a 0
	 * @param int y  - inicializada a 0
	 */
	Coordenadas() {
		this->x = 0;
		this->y = 0;
	}
	/**
	 * @brief Funcao de retorno para a coordenada X
	 * @return int x
	 */
	int getX() {
		return this->x;
	}

	/**
	 * @brief Funcao de retorno para a coordenada Y
	 * @return int y
	 */
	int getY() {
		return this->y;
	}

	/**
	 * @brief Funcao modificadora para a coordenada X
	 * @param int x
	 */
	void setX(int x) {
		this->x = x;
	}

	/**
	 * @brief Funcao modificadora para a coordenada Y
	 * @param int y
	 */
	void setY(int y) {
		this->y = y;
	}

	/**
	 * @brief Funcao modificadora para as coordenadas X,Y
	 * @param int x
	 * @param int y
	 */
	void setCoordenadas(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

#endif /* COORDENADAS_H_ */

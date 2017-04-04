/*
 * Hora.h
 *
 *  Created on: 04/04/2017
 *      Author: beatrizHm
 */

#ifndef SRC_HORA_H_
#define SRC_HORA_H_

class Hora {
	int hora;
	int minutos;
public:
	Hora();

	Hora(int hora, int minutos);

	int getHora() const;

	int getMinutos() const;

	void setHora(int hora);

	void setMinutos(int minutos);
};

#endif /* SRC_HORA_H_ */

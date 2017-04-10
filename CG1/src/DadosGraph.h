/*
 * DadosGraph.h
 *
 *  Created on: 04/04/2017
 *      Author: beatrizHm
 */

#ifndef SRC_DADOSGRAPH_H_
#define SRC_DADOSGRAPH_H_

class DadosGraph {
	int idAresta;
	int idOrigem;
	int idDestino;
	string edgeLabel;
public:
	DadosGraph(int idAresta, int idOrigem, int idDestino, string edgeLabel) {
		this->idAresta = idAresta;
		this->idOrigem = idOrigem;
		this->idDestino = idDestino;
		this->edgeLabel = edgeLabel;
	}

	int getIdAresta() const {
		return idAresta;
	}

	int getIdDestino() const {
		return idDestino;
	}

	int getIdOrigem() const {
		return idOrigem;
	}

	void setIdAresta(int idAresta) {
		this->idAresta = idAresta;
	}

	void setIdDestino(int idDestino) {
		this->idDestino = idDestino;
	}

	void setIdOrigem(int idOrigem) {
		this->idOrigem = idOrigem;
	}

	string getEdgeLabel() {
		return this->edgeLabel;
	}
};

#endif /* SRC_DADOSGRAPH_H_ */

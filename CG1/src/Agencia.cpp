#include "Agencia.h"

void Agencia::lerFicheiroClientes() {
	ifstream fileC("clientes.txt");

	if (fileC.is_open()) {
		string lixo;

		vector<Cliente*> aux;

		string line;
		while (getline(fileC, line)) {

			stringstream ss(line);

			int id;
			string nome;
			string morada;
			string email;
			long nt;
			long nif;
			long segSocial;

			ss >> id;
			getline(ss, lixo, ';');

			getline(ss, nome, ';');

			ss >> nt;
			getline(ss, lixo, ';');

			ss >> segSocial;
			getline(ss, lixo, ';');

			ss >> nif;
			getline(ss, lixo, ';');

			getline(ss, morada, ';');

			getline(ss, email, '\n');

			trim(nome);
			trim(morada);
			trim(email);

			Cliente* c = new Cliente(nome, nt, segSocial, nif, morada, email);

			this->clientes.push_back(c);
			fileC.close();
		}
	} else {
		cout << endl << "Não conseguiu abrir ficheiro de Clientes" << endl
				<< endl << endl;
	}
}
/*
void Agencia::lerFicheiroAvioes() {
	ifstream fileA("aviao.txt");

	if (fileA.is_open()) {
		string lixo;

		string line;

		getline(fileA, line);
		stringstream ss(line);

		string tipoTrans;
		getline(ss, tipoTrans, '\n');

		while (getline(fileA, line)) {

			stringstream ss(line);

			string origem;
			string destino;
			int dia;
			int mes;
			int ano;
			int hora;
			int min;
			int horaD;
			int minD;
			float preco;

			getline(ss, origem, ';');

			trim(origem);

			getline(ss, destino, ';');

			trim(destino);

			ss >> dia;
			getline(ss, lixo, '/');

			ss >> mes;
			getline(ss, lixo, '/');

			ss >> ano;
			getline(ss, lixo, ';');

			ss >> hora;
			getline(ss, lixo, ':');

			ss >> min;
			getline(ss, lixo, ';');

			ss >> horaD;
			getline(ss, lixo, ':');

			ss >> minD;
			getline(ss, lixo, ';');

			ss >> preco;
			getline(ss, lixo, '\n');

			Data data = Data(dia, mes, ano);
			Hora horaPartida = Hora(hora, min);
			Hora duracao = Hora(horaD, minD);
			Transporte trans = Transporte(AVIAO, origem, destino, data,
					horaPartida, duracao, preco);
		}
	} else {
		cout << endl << "Não conseguiu abrir ficheiro de Voos" << endl << endl
				<< endl;
	}
}*/

void Agencia::escreverFicheiroClientes() {
	ofstream file("clientes.txt");

	file.clear();

	for (unsigned int j = 0; j < this->clientes.size(); j++) {
		int id = this->clientes[j]->getID();
		string nome = this->clientes[j]->getNome();
		unsigned long nt = this->clientes[j]->getNumTelefone();
		unsigned long ss = this->clientes[j]->getSs();
		unsigned long nif = this->clientes[j]->getNif();
		string morada = this->clientes[j]->getMorada();
		string email = this->clientes[j]->getEmail();

		if (this->clientes.size() - 1 == j) {
			file << id << " ; " << nome << " ; " << nt << " ; " << ss << " ; "
					<< nif << " ; " << morada << " ; " << email;
		} else {
			file << id << " ; " << nome << " ; " << nt << " ; " << ss << " ; "
					<< nif << " ; " << morada << " ; " << email << endl;
		}
	}

	cout << endl << "Ficheiro Clientes gravado com sucesso!" << endl << endl;

	file.close();
}

void Agencia::escreverFicheiroAvioes() {
	ofstream file("aviao.txt");

	file.clear();

	string origem;
	string destino;
	int dia;
	int mes;
	int ano;
	int hora;
	int min;
	int horaD;
	int minD;
	float preco;

	file << "AVIAO" << endl;

	file << origem << " ; " << destino << " ; " << dia << " / " << mes << " / "
			<< ano << " ; " << hora << " : " << min << " ; " << horaD << " : "
			<< minD << " ; " << preco << endl;

	cout << endl << "Ficheiro Voos gravado com sucesso!" << endl << endl;

	file.close();
}

void Agencia::trim(string &str) {
	if (str.size() != 0) {
		size_t first = str.find_first_not_of(" ");
		str = str.substr(first, (str.size() - first));
		size_t last = str.find_last_not_of(" ");
		str = str.substr(0, last + 1);
	}
}

Agencia::Agencia() {
	
	lerFicheiroClientes();

	//lerFicheiroAvioes();

	menuInicial();


}

vector<Cliente*> Agencia::getClientes() const {
	return clientes;
}

void Agencia::setClientes(vector<Cliente*> clientes) {
	this->clientes = clientes;
}

void Agencia::menuInicial() {
	cout << "************************" << endl;
	cout << "| Menu Agencia Viagens |" << endl;
	cout << "************************" << endl;

	cout << setw(5) << " " << "1. Novo Cliente" << endl;
	cout << setw(5) << " " << "2. Listagem de Cliente" << endl;
	cout << setw(5) << " " << "3. Procura Cliente" << endl;
	cout << setw(5) << " " << "4. Nova Viagem" << endl;
	cout << setw(5) << " " << "5. Listagem de Destinos" << endl;
	cout << setw(5) << " " << "6. Sair" << endl;

	int op;

	cout << "Opção: ";
	cin >> op;

	if (op > 6 || op < 1) {
		cout << "Seleccione uma opcao valida!" << endl << endl << endl;
		menuInicial();
	}

	if (op == 1) {
		menuNovoCliente();
	} else if (op == 2) {
		menuListaClientes();
	} else if (op == 3) {
		menuProcuraClientes();
	} else if (op == 4) {
		novaViagem();
	} else if (op == 5) {
		menuListaDestinos();
	} else if (op == 6) {
		escreverFicheiroClientes();
		//escreverFicheiroAvioes();
		exit(0);
	}
}

void Agencia::menuNovoCliente() {
	cin.ignore(1);
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------------" << endl;
	cout << setw(5) << " " << "| Menu Novo Cliente |" << endl;
	cout << setw(5) << " " << "---------------------" << endl;
	cout << endl;

	int numeroValido = 0;
	unsigned long nif;
	do {
		cout << setw(8) << " " << "NIF: ";
		cin >> nif;
		numeroValido = lengthNumber(nif);
	} while (nif == NULL && numeroValido != 8);

	if (procuraCliente(nif) != -1) {
		cout << setw(8) << " " << "Cliente ja existe!" << endl;
		menuInicial();
	}

	cin.ignore(1);
	string nome = "";
	do {
		cout << endl << setw(8) << " " << "Nome: ";
		getline(cin, nome);
	} while (nome == "");

	unsigned long numTel = 0;
	do {
		cout << endl << setw(8) << " " << "Numero Telemovel: ";
		cin >> numTel;
		numeroValido = lengthNumber(numTel);
	} while (numTel == NULL && numeroValido != 9);

	unsigned long ss = 0;
	do {
		cout << endl << setw(8) << " " << "Segurança Social: ";
		cin >> ss;
		numeroValido = lengthNumber(ss);
	} while (ss == NULL && numeroValido != 11);

	cin.ignore(1);
	string morada = "";
	do {
		cout << endl << setw(8) << " " << "Morada: ";
		getline(cin, morada);
	} while (morada == "");

	string email = "";
	do {
		cout << endl << setw(8) << " " << "Email: ";
		getline(cin, email);
	} while (email == "");

	trim(nome);
	trim(morada);
	trim(email);

	Cliente* nC = new Cliente(nome, numTel, ss, nif, morada, email);

	this->clientes.push_back(nC);

	cout << endl << endl << setw(8) << " " << "Novo Cliente criado com sucesso!"
			<< endl << endl << endl;

	menuInicial();
}

void Agencia::menuListaClientes() {
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------------" << endl;
	cout << setw(5) << " " << "| Lista de Clientes |" << endl;
	cout << setw(5) << " " << "---------------------" << endl;
	cout << endl;

	cout << setw(8) << " " << setw(4) << "ID" << setw(39) << " " << "Nome"
			<< setw(13) << "Telemovel" << setw(14) << "SS" << setw(11) << "NIF"
			<< setw(40) << "Morada" << setw(23) << "Email" << endl;

	for (int i = 0; i < this->clientes.size(); i++) {
		cout << setw(8) << " " << setw(4) << this->clientes[i]->getID()
				<< setw(3) << " " << setw(40) << this->clientes[i]->getNome()
				<< setw(3) << " " << setw(9)
				<< this->clientes[i]->getNumTelefone() << setw(3) << " "
				<< setw(11) << this->clientes[i]->getSs() << setw(3) << " "
				<< setw(8) << this->clientes[i]->getNif() << setw(3) << " "
				<< setw(38) << this->clientes[i]->getMorada() << setw(3) << " "
				<< setw(15) << this->clientes[i]->getEmail() << endl;
	}

	cout << endl << endl << endl;
	menuInicial();
}

void Agencia::menuProcuraClientes() {
	cin.ignore(1);
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "----------------------" << endl;
	cout << setw(5) << " " << "| Procura de Cliente |" << endl;
	cout << setw(5) << " " << "----------------------" << endl;
	cout << endl << endl;

	int numeroValido = 0;
	unsigned long nif;
	do {
		cout << setw(8) << " " << "Introduza o nif do Cliente: ";
		cin >> nif;
		numeroValido = lengthNumber(nif);
	} while (nif == NULL && numeroValido != 8);

	int ind = procuraCliente(nif);

	if (ind == -1) {
		cout << endl << endl << setw(8) << " " << "Cliente com o nif " << nif
				<< " nao existe!" << endl << endl;
	} else {
		cout << endl;
		cout << setw(8) << " " << "Dados Cliente: " << endl;
		cout << setw(26) << " " << "ID: " << this->clientes[ind]->getID()
				<< endl;
		cout << setw(24) << " " << "Nome: " << this->clientes[ind]->getNome()
				<< endl;
		cout << setw(12) << " " << "Numero Telemovel: "
				<< this->clientes[ind]->getNumTelefone() << endl;
		cout << setw(12) << " " << "Seguranca Social: "
				<< this->clientes[ind]->getSs() << endl;
		cout << setw(25) << " " << "NIF: " << this->clientes[ind]->getNif()
				<< endl;
		cout << setw(22) << " " << "Morada: "
				<< this->clientes[ind]->getMorada() << endl;
		cout << setw(23) << " " << "Email: " << this->clientes[ind]->getEmail()
				<< endl;
	}
	cout << endl;

	menuInicial();
}


void Agencia::novaViagem() {
	
	cin.ignore(1);
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------" << endl;
	cout << setw(5) << " " << "| Nova Viagem |" << endl;
	cout << setw(5) << " " << "---------------" << endl;
	cout << endl << endl;

	Viagem viagem;
	int peso = 1;

	int dia;
	int mes;
	int ano;
	
	cin.ignore(1);
	string ida;
	cout << setw(8) << " " << "Data de ida: ";
	
	getline(cin, ida);
	stringstream ss(ida);
	ss >> dia;
	getline(ss, ida, '/');
	ss >> mes;
	getline(ss, ida, '/');
	ss >> ano;

	Data dataIda(dia, mes, ano);

	
	string volta;
	cout << setw(8) << " " << "Data de volta (insira 0 se nao aplicavel): ";
	getline(cin, volta);
	Data dataVolta;

	if (atoi(volta.c_str()) == 0) { 
		 viagem = Viagem(dataIda);
		//dataVolta = Data(); 
	}
	else {
		stringstream ss(volta);
		ss >> dia;
		getline(ss, volta, '/');
		ss >> mes;
		getline(ss, volta, '/');
		ss >> ano;
		dataVolta= Data(dia, mes, ano);
		 viagem = Viagem(dataIda, dataVolta);
	}
	

	carregarGrafo(peso,viagem);
	
	getchar();
	escolhaDestinos();

	//cout << endl << "|" << partida << "|" << setw(4) << " " << "|" << destino
		//<< "|" << endl;
}

void Agencia::menuListaDestinos() {
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------------" << endl;
	cout << setw(5) << " " << "| Lista de Clientes |" << endl;
	cout << setw(5) << " " << "---------------------" << endl;
	cout << endl;

	cout << setw(8) << " " << setw(15) << "Partida" << setw(3) << "-"
			<< setw(15) << "Destino" << endl;

	menuInicial();
}

int Agencia::procuraCliente(unsigned long nif) {
	for (unsigned int i = 0; i < this->clientes.size(); i++) {
		if (this->clientes[i]->getNif() == nif) {
			return i;
		}
	}

	return -1;
}

int Agencia::lengthNumber(int n) {
	int cont = 0;
	while (n) {
		n = n / 10;
		cont++;
	}
	return cont;
}

void Agencia::carregarGrafo(int choice, Viagem viag){
	
	int edgeId = 0;
	Cidade tempo;
	
	srand(time(NULL));

	// inicializador graphviewer
	GraphViewer *gv = new GraphViewer(800, 601, false);

	gv->setBackground("escala200km.png");

	gv->createWindow(800, 601);

	gv->defineEdgeDashed(true);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	Cidade ultima = Cidade(-1, "", Coordenadas());
	int lastId = -1;


	ifstream cidades("cidades.txt");
	
	
	if (cidades.is_open()) {

		string linha;

		
		while (!cidades.eof()) {
			Coordenadas coordenadas;
			int x, y, id;
			string nome;

			getline(cidades, linha);
			id = atoi(linha.c_str());

			getline(cidades, linha);
			nome = linha;

			getline(cidades, linha);
			x = atoi(linha.c_str());

			getline(cidades, linha);
			y = atoi(linha.c_str());

			Cidade cidade = Cidade(id, nome, Coordenadas(x,y));

			int random = rand() % 12 + 1;

			if (grafo.addVertex(cidade)) {
				gv->addNode(id, x, y);
				gv->setVertexLabel(id, nome);
				gv->setVertexSize(id, 15);
				gv->setVertexColor(id, cores[random]);
				tempo = Cidade(id, nome, Coordenadas(x, y));
			}

	// ENCHER COM VIAGENS DE AVIAO (DIRETAS)
		
			Hora partida = Hora(6, 33);
			Transporte aviao = Transporte(AVIAO, partida);
			Viagem viagemGrafo;

			if (lastId == -1)
			{
				lastId = id;
			}
			else
				{

				/*if (choice == 1)
				{*/
					//ligacao com cidade  anterior

					viagemGrafo = criadorViagem(ultima, tempo, viag, aviao);
				
					grafo.addEdge(ultima, tempo, viagemGrafo);
					grafo.addEdge(tempo, ultima, viagemGrafo);
					
					gv->addEdge(edgeId, lastId, id, EdgeType::UNDIRECTED);
					gv->setEdgeLabel(edgeId, "aviao");

					dadosGrafo.push_back(DadosGraph(edgeId, lastId, id, "aviao"));
					dadosGrafo.push_back(DadosGraph(edgeId, id, lastId,"aviao"));
					lastId = id;
					edgeId++;


				/*
						for (size_t i = 0; i < grafo.getNumVertex(); i++)	{
						
							if (grafo.getVertexSet()[i]->getInfo().getId() != tempo.getId() && grafo.getVertexSet()[i]->getInfo().getId() != ultima.getId()) {
							
							int newid = grafo.getVertexSet()[i]->getInfo().getId();
							Cidade newcidade = grafo.getVertexSet()[i]->getInfo();
							

							viagemGrafo = criadorViagem(grafo.getVertexSet()[i]->getInfo(), tempo, viag, aviao);

							grafo.addEdge(newcidade, tempo, viagemGrafo);
							grafo.addEdge(tempo, newcidade, viagemGrafo);

							gv->addEdge(edgeId, newid, id, EdgeType::UNDIRECTED);
							gv->setEdgeLabel(edgeId, "aviao");

							dadosGrafo.push_back(DadosGraph(edgeId, newid, id, "aviao"));
							dadosGrafo.push_back(DadosGraph(edgeId, id, newid, "aviao"));

							edgeId++;
						}
					}*/
					

				/*}
				else
				{					
					graph.addEdge(ultima, tempo, travel, line);
					graph.addEdge(tempo, ultima, dist * MAP_TO_METERS, line);
					gv->addEdge(edgeId, lastId, id, EdgeType::UNDIRECTED);
					dg.push_back(DadosGraficos(edgeId, lastId, id));
					dg.push_back(DadosGraficos(edgeId, id, lastId));
					lastId = id;
					edgeId++;
				}*/
			}

			ultima = tempo;

		}

			cidades.close();
		}
	else {
		cout << endl << "Não conseguiu abrir ficheiro de cidades" << endl << endl << endl;
	}

	/*
	

	// carregador de viagens de BUS

	Hora partida = Hora(9, 33);
	Transporte bus = Transporte(BUS, partida);


	// porto lisboa
	Viagem viagemGrafoBUS = criadorViagem(grafo.getVertexSet()[0]->getInfo(), grafo.getVertexSet()[1]->getInfo(), viag, bus);
	grafo.addEdge(grafo.getVertexSet()[0]->getInfo(), grafo.getVertexSet()[1]->getInfo(), viagemGrafoBUS); 
	grafo.addEdge(grafo.getVertexSet()[1]->getInfo(), grafo.getVertexSet()[0]->getInfo(), viagemGrafoBUS);
	
	gv->addEdge(edgeId, grafo.getVertexSet()[0]->getInfo().getId(), grafo.getVertexSet()[1]->getInfo().getId(), EdgeType::UNDIRECTED);
	gv->setEdgeLabel(edgeId, "bus");


	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[0]->getInfo().getId(), grafo.getVertexSet()[1]->getInfo().getId(), "bus"));
	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[1]->getInfo().getId(), grafo.getVertexSet()[0]->getInfo().getId(), "bus"));

	edgeId++;


	// lisboa madrid
	viagemGrafoBUS = criadorViagem(grafo.getVertexSet()[0]->getInfo(), grafo.getVertexSet()[2]->getInfo(), viag, bus);
	grafo.addEdge(grafo.getVertexSet()[0]->getInfo(), grafo.getVertexSet()[2]->getInfo(), viagemGrafoBUS);
	grafo.addEdge(grafo.getVertexSet()[2]->getInfo(), grafo.getVertexSet()[0]->getInfo(), viagemGrafoBUS);

	gv->addEdge(edgeId, grafo.getVertexSet()[0]->getInfo().getId(), grafo.getVertexSet()[2]->getInfo().getId(), EdgeType::UNDIRECTED);
	gv->setEdgeLabel(edgeId, "bus");


	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[0]->getInfo().getId(), grafo.getVertexSet()[2]->getInfo().getId(), "bus"));
	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[2]->getInfo().getId(), grafo.getVertexSet()[0]->getInfo().getId(), "bus"));

	edgeId++;

	// madrid paris (ou seja da lisboa- madrid-paris)
	viagemGrafoBUS = criadorViagem(grafo.getVertexSet()[4]->getInfo(), grafo.getVertexSet()[2]->getInfo(), viag, bus);
	grafo.addEdge(grafo.getVertexSet()[4]->getInfo(), grafo.getVertexSet()[2]->getInfo(), viagemGrafoBUS);
	grafo.addEdge(grafo.getVertexSet()[2]->getInfo(), grafo.getVertexSet()[4]->getInfo(), viagemGrafoBUS);

	gv->addEdge(edgeId, grafo.getVertexSet()[4]->getInfo().getId(), grafo.getVertexSet()[2]->getInfo().getId(), EdgeType::UNDIRECTED);
	gv->setEdgeLabel(edgeId, "bus");


	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[4]->getInfo().getId(), grafo.getVertexSet()[2]->getInfo().getId(), "bus"));
	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[2]->getInfo().getId(), grafo.getVertexSet()[4]->getInfo().getId(),"bus"));

	edgeId++;

	// porto sevilha 

	viagemGrafoBUS = criadorViagem(grafo.getVertexSet()[1]->getInfo(), grafo.getVertexSet()[7]->getInfo(), viag, bus);
	grafo.addEdge(grafo.getVertexSet()[7]->getInfo(), grafo.getVertexSet()[1]->getInfo(), viagemGrafoBUS);
	grafo.addEdge(grafo.getVertexSet()[1]->getInfo(), grafo.getVertexSet()[7]->getInfo(), viagemGrafoBUS);

	gv->addEdge(edgeId, grafo.getVertexSet()[7]->getInfo().getId(), grafo.getVertexSet()[1]->getInfo().getId(), EdgeType::UNDIRECTED);
	gv->setEdgeLabel(edgeId, "bus");


	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[7]->getInfo().getId(), grafo.getVertexSet()[1]->getInfo().getId(), "bus"));
	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[1]->getInfo().getId(), grafo.getVertexSet()[7]->getInfo().getId(), "bus"));

	edgeId++;

	// sevilha barcelona (porto - sevilha - barcelona)

	viagemGrafoBUS = criadorViagem(grafo.getVertexSet()[4]->getInfo(), grafo.getVertexSet()[7]->getInfo(), viag, bus);
	grafo.addEdge(grafo.getVertexSet()[7]->getInfo(), grafo.getVertexSet()[4]->getInfo(), viagemGrafoBUS);
	grafo.addEdge(grafo.getVertexSet()[4]->getInfo(), grafo.getVertexSet()[7]->getInfo(), viagemGrafoBUS);

	gv->addEdge(edgeId, grafo.getVertexSet()[7]->getInfo().getId(), grafo.getVertexSet()[4]->getInfo().getId(), EdgeType::UNDIRECTED);
	gv->setEdgeLabel(edgeId, "bus");


	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[7]->getInfo().getId(), grafo.getVertexSet()[4]->getInfo().getId(), "bus"));
	dadosGrafo.push_back(DadosGraph(edgeId, grafo.getVertexSet()[4]->getInfo().getId(), grafo.getVertexSet()[7]->getInfo().getId(), "bus"));

	edgeId++;

	*/


}

Viagem Agencia::criadorViagem(Cidade ponto1, Cidade ponto2, Viagem viag, Transporte T) {

	Viagem viagemRetornada;

	viagemRetornada.setPeriodo(viag.getPeriodo());

	float distanciaMapa = sqrt(((abs(ponto1.getCoordenadas().getY() - ponto2.getCoordenadas().getY())) ^ 2) + ((abs(ponto1.getCoordenadas().getX() - ponto2.getCoordenadas().getX())) ^ 2));
	
	float distanciaReal = distanciaMapa * MAP_TO_KM;
	
	float duracaoViagem;
	
	if (T.getTipo() == AVIAO)
	 duracaoViagem = distanciaReal / VEL_MED_AVIAO;
	else if (T.getTipo() == BUS)
	 duracaoViagem = distanciaReal / VEL_MED_BUS;

	int duracaoHoras = duracaoViagem;
	double minutesRemainder = (duracaoViagem - duracaoHoras) * 60;
	int duracaoMinutos = minutesRemainder;

	Hora duracao = Hora(duracaoHoras, duracaoMinutos);

	stringstream ss;
	ss << "A viagem demorara " << duracaoHoras << " e " << duracaoMinutos << " minutos.";

	int taxa;

	
	
	switch (viagemRetornada.getPeriodo()) {
	case epocaALTA:
		if (T.getTipo() == AVIAO )taxa = 6;
		if (T.getTipo() == BUS) taxa = 3;
		break;
	case epocaMEDIA:
		if (T.getTipo() == AVIAO)taxa = 3;
		if (T.getTipo() == BUS) taxa = 1.5;
		break;
	case epocaBAIXA:
		if (T.getTipo() == AVIAO) taxa = 2;
		if (T.getTipo() == BUS) taxa = 1;
		break;
	case nonDEFINED:
		taxa = 0;
		break;
	}

	float custoViagem = distanciaMapa * taxa;
	

	T.setPreco(custoViagem);
	T.setDuracao(duracao);
	viagemRetornada.setDistancia(distanciaReal);

	viagemRetornada.addTransporte(T);

	return viagemRetornada;


}

void Agencia::escolhaDestinos() {
	string partida;
	int partidaId;
	string destino;
	int destinoId;

	cout << "Por favor insira um local de partida";
	cin >> partida;

	partidaId = converteCidadeparaID(partida);


	cout << " Por favor insira o destino pretendido";
	cin >> destino;
	destinoId = converteCidadeparaID(destino);
	
	if (destino == partida) {
		cout << "O destino nao pode ser igual ao local de partida por favor tente novamente." << endl;
		return;
	}


	


	// inicializador graphviewer
	GraphViewer *gvFinal = new GraphViewer(800, 601, false);

	gvFinal->setBackground("escala200km.png");

	gvFinal->createWindow(800, 601);

	gvFinal->defineEdgeDashed(true);
	gvFinal->defineVertexColor("blue");
	gvFinal->defineEdgeColor("black");

	for (size_t i = 0; i < grafo.getNumVertex(); i++)
	{
		gvFinal->addNode(grafo.getVertexSet()[i]->getInfo().getId(), grafo.getVertexSet()[i]->getInfo().getCoordenadas().getX(), grafo.getVertexSet()[i]->getInfo().getCoordenadas().getY());
		gvFinal->setVertexLabel(grafo.getVertexSet()[i]->getInfo().getId(), grafo.getVertexSet()[i]->getInfo().getNome());
		gvFinal->setVertexSize(grafo.getVertexSet()[i]->getInfo().getId(), 15);
		gvFinal->setVertexColor(grafo.getVertexSet()[i]->getInfo().getId(), "BLACK");

	}

	
	
	
	
	
	for (size_t i = 0; i < dadosGrafo.size(); i++)
	{
		if (dadosGrafo[i].getIdOrigem() == partidaId  ) {
			gvFinal->addEdge(dadosGrafo[i].getIdAresta(), dadosGrafo[i].getIdDestino(), dadosGrafo[i].getIdOrigem(), EdgeType::UNDIRECTED);
			gvFinal->setEdgeLabel(dadosGrafo[i].getIdAresta(), dadosGrafo[i].getEdgeLabel());
		}
	}

	cin.ignore();
	getchar();

	grafo.dijkstraShortestPath(grafo.getVertexSet()[partidaId - 1]->getInfo());
	vector<Cidade> caminho = grafo.getPath(grafo.getVertexSet()[partidaId - 1]->getInfo(), grafo.getVertexSet()[destinoId - 1]->getInfo());

	cout << "\n\n O preco total da viagem e: " << grafo.getVertexSet()[destinoId - 1]->getDist() << " euros" << endl;

	cin.ignore();
	getchar();
}

int Agencia::converteCidadeparaID(string cidade) {

	for (size_t i = 0; i < grafo.getNumVertex(); i++)
	{
		if (grafo.getVertexSet()[i]->getInfo().getNome() == cidade)
			return grafo.getVertexSet()[i]->getInfo().getId();
	}

	return 0;
}
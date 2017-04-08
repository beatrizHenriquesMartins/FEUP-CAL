#include "Menu.h"
#include "Data.h"

void Menu::lerFicheiroClientes() {
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
			string nts;
			unsigned long nt;
			string nifs;
			unsigned long  nif;
			string segsocials;
			unsigned long long segSocial;

			ss >> id;
			getline(ss, lixo, ';');

			getline(ss, nome, ';');

			getline(ss, nts, ';');
			trim(nts);
			nt = atol(nts.c_str());

			getline(ss, segsocials, ';');
			trim(segsocials);
			segSocial = atoll(segsocials.c_str());

			ss >> nif;
			getline(ss, lixo, ';');

			getline(ss, morada, ';');

			getline(ss, email, '\n');

			trim(nome);
			trim(morada);
			trim(email);

			Cliente* c = new Cliente(nome, nt, segSocial, nif, morada, email);

			this->clientes.push_back(c);
		}
	} else {
		cout << endl << "Não conseguiu abrir ficheiro de Clientes" << endl
				<< endl << endl;
	}
}

void Menu::lerFicheiroAvioes() {
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
}

void Menu::escreverFicheiroClientes() {
	ofstream file("clientes.txt");

	file.clear();

	for (unsigned int j = 0; j < this->clientes.size(); j++) {
		int id = this->clientes[j]->getID();
		string nome = this->clientes[j]->getNome();
		unsigned long nt = this->clientes[j]->getNumTelefone();
		unsigned long long ss = this->clientes[j]->getSs();
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

void Menu::escreverFicheiroAvioes() {
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

void Menu::trim(string &str) {
	if (str.size() != 0) {
		size_t first = str.find_first_not_of(" ");
		str = str.substr(first, (str.size() - first));
		size_t last = str.find_last_not_of(" ");
		str = str.substr(0, last + 1);
	}
}

Menu::Menu() {
	
	lerFicheiroClientes();

	lerFicheiroAvioes();

	menuInicial();


}

vector<Cliente*> Menu::getClientes() const {
	return clientes;
}

void Menu::setClientes(vector<Cliente*> clientes) {
	this->clientes = clientes;
}

void Menu::menuInicial() {
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

	cout << "Opcao: ";
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
		menuNovaViagem();
	} else if (op == 5) {
		menuListaDestinos();
	} else if (op == 6) {
		escreverFicheiroClientes();
		//escreverFicheiroAvioes();
		exit(0);
	}
}

void Menu::menuNovoCliente() {
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

	unsigned long long ss = 0;
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

void Menu::menuListaClientes() {
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------------" << endl;
	cout << setw(5) << " " << "| Lista de Clientes |" << endl;
	cout << setw(5) << " " << "---------------------" << endl;
	cout << endl;

	cout << setw(8) << " " << setw(4) << "ID" << setw(39) << " " << "Nome"
			<< setw(12) << "Telemovel" << setw(14) << "SS" << setw(11) << "NIF"
			<< setw(41) << "Morada" << setw(23) << "Email" << endl;

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

void Menu::menuProcuraClientes() {
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

void Menu::menuNovaViagem() {
	
	cin.ignore(1);
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------" << endl;
	cout << setw(5) << " " << "| Nova Viagem |" << endl;
	cout << setw(5) << " " << "---------------" << endl;
	cout << endl << endl;

	
	
	string partida;
	cout << setw(8) << " " << "Partida: ";
	getline(cin, partida);

	string destino;
	cout << setw(8) << " " << "Destino: ";
	getline(cin, destino);

	Data ida;
	cout << setw(8) << " " << "Insira uma data de ida: ";
	




	cout << endl << "|" << partida << "|" << setw(4) << " " << "|" << destino
			<< "|" << endl;

	menuInicial();
}

void Menu::menuListaDestinos() {
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------------" << endl;
	cout << setw(5) << " " << "| Lista de Clientes |" << endl;
	cout << setw(5) << " " << "---------------------" << endl;
	cout << endl;

	cout << setw(8) << " " << setw(15) << "Partida" << setw(3) << "-"
			<< setw(15) << "Destino" << endl;

	menuInicial();
}

int Menu::procuraCliente(unsigned long nif) {
	for (unsigned int i = 0; i < this->clientes.size(); i++) {
		if (this->clientes[i]->getNif() == nif) {
			return i;
		}
	}

	return -1;
}

int Menu::lengthNumber(int n) {
	int cont = 0;
	while (n) {
		n = n / 10;
		cont++;
	}
	return cont;
}

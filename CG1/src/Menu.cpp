#include "Menu.h"

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
		}
	} else {
		cout << endl << "Não conseguiu abrir ficheiro de Clientes" << endl
				<< endl << endl;
	}
}

void Menu::escreverFicheiroClientes() {
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

	cout << endl << "Ficheiro gravado com sucesso!" << endl << endl;

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
	cout << "| Menu Agência Viagens |" << endl;
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
		cout << "Seleccione uma opção válida!" << endl << endl << endl;
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
		cout << setw(8) << " " << "Cliente já existe!" << endl;
		menuInicial();
	}

	cin.ignore(1);
	string nome;
	do {
		cout << endl << setw(8) << " " << "Nome: ";
		getline(cin, nome);
	} while (nome == "");

	unsigned long numTel;
	do {
		cout << endl << setw(8) << " " << "Número Telemóvel: ";
		cin >> numTel;
		numeroValido = lengthNumber(numTel);
	} while (numTel == NULL && numeroValido != 9);

	unsigned long ss;
	do {
		cout << endl << setw(8) << " " << "Segurança Social: ";
		cin >> ss;
		numeroValido = lengthNumber(ss);
	} while (ss == NULL && numeroValido != 11);

	cin.ignore(1);
	string morada;
	do {
		cout << endl << setw(8) << " " << "Morada: ";
		getline(cin, morada);
	} while (morada == "");

	string email;
	do {
		cout << endl << setw(8) << " " << "Email: ";
		getline(cin, email);
	} while (email == "");

	trim(nome);
	trim(morada);
	trim(email);

	Cliente* nC = new Cliente(nome, numTel, ss, nif, morada, email);

	this->clientes.push_back(nC);

	cout << endl << setw(8) << " " << "Novo Cliente criado com sucesso" << endl
			<< endl << endl;

	menuInicial();
}

void Menu::menuListaClientes() {
	cout << "\n" << "\n" << "\n" << "\n";
	cout << setw(5) << " " << "---------------------" << endl;
	cout << setw(5) << " " << "| Lista de Clientes |" << endl;
	cout << setw(5) << " " << "---------------------" << endl;
	cout << endl;

	cout << setw(8) << " " << setw(4) << "ID" << setw(49) << " " << "Nome"
			<< setw(13) << "Telemóvel" << setw(14) << "SS" << setw(11) << "NIF"
			<< setw(52) << "Morada" << setw(23) << "Email" << endl;

	for (int i = 0; i < this->clientes.size(); i++) {
		cout << setw(8) << " " << setw(4) << this->clientes[i]->getID()
				<< setw(3) << " " << setw(50) << this->clientes[i]->getNome()
				<< setw(3) << " " << setw(9)
				<< this->clientes[i]->getNumTelefone() << setw(3) << " "
				<< setw(11) << this->clientes[i]->getSs() << setw(3) << " "
				<< setw(8) << this->clientes[i]->getNif() << setw(3) << " "
				<< setw(50) << this->clientes[i]->getMorada() << setw(3) << " "
				<< setw(20) << this->clientes[i]->getEmail() << endl;
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
				<< " não existe!" << endl << endl;
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


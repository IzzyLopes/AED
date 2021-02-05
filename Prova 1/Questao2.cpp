//Isabela Lopes - 190088940
// QUESTÃO 2 - CARRO
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Veiculos {
	string nome, placa, cor, telefone, marca;
	
	public:
		Veiculos() {
			nome = "N/A";
			placa = "N/A";
			marca = "N/A";
			cor = "N/A";
			telefone = "N/A";
		}
		
		string get_Veiculos() {
			return "Nome: " + nome + "\n" + "Telefone: " + telefone + "\n" + "Marca do Carro: " + marca + "\n" + "Placa do Carro: " + placa + "\n" + "Cor do Carro: " + cor + "\n";
		}
		
		string get_nome() {
			return nome;
		}
		
		string get_placa() {
			return placa;
		}
		
		string get_cor() {
			return cor;
		}
		
		string get_telefone() {
			return telefone;
		}
		
		string get_marca() {
			return marca;
		}
		
		void set_nome(string name){
			nome = name;
		}
		
		void set_placa(string novaPlaca) {
			placa = novaPlaca;
		}
		
		void set_cor(string color) {
			cor = color;
		}
		
		void set_telefone(string phone) {
			telefone = phone;
		}
		
		void set_marca(string novaMarca) {
			marca = novaMarca;
		}
};

int main () {
	Veiculos v1;

	int menu;
	string cadastro;
	vector <string> cadastrador;
	vector <string>::iterator ponteiro;
	
	string n, t, m, p, c;	
	
	cout << "\t***** CLIENTES CADASTRADOS *****" << endl;
	cout << v1.get_Veiculos();
	cout << "\n\nDeseja cadastrar mais clientes?" << endl << "Se sim, digite a quantidade de clientes deseja cadastrar." << endl << "Se nao, digite 0" << endl;
	cin >> menu;
	
	while (menu !=0) {
		for (int i=0; i<menu; i++) { // Criei esse for pra ele ir fazendo cadastros até chegar no número que a pessoa digitou.
			cout << "\nCliente " << i + 1 << endl;
			cout << "Nome (no formato last name,name) \nSem espacos: ";
			cin >> n;
			v1.set_nome(n);
			
			cout << "Telefone no formato (xx)xxxxx-xxxx: ";
			cin >> t;
			v1.set_telefone(t);
			
			cout << "Marca do Carro: ";
			cin >> m;
			v1.set_marca(m);
			
			cout << "Placa do Carro: ";
			cin >> p;
			v1.set_placa(p);
			
			cout << "Cor do Carro: ";
			cin >> c;
			v1.set_cor(c);
			
			cadastrador.push_back(v1.get_Veiculos());
			
			ofstream account("cadastro.txt"); // Salvar no arquivo
			for (ponteiro=cadastrador.begin(); ponteiro<cadastrador.end(); ponteiro++) {
				account << *ponteiro << endl;
			}
		}
		
		system("cls");
		cout << "\t***** CLIENTES CADASTRADOS *****" << endl;
		ifstream listagem("cadastro.txt"); // Abrir arquivo
		string arquivo;
	
		if(listagem.is_open()) {
			while(! listagem.eof()) {
				getline (listagem, arquivo);
				cout << "\n" << arquivo;
				cadastrador.push_back(arquivo);
			}
			listagem.close();
		}
		
		break;
	}
	
	return 0;
}

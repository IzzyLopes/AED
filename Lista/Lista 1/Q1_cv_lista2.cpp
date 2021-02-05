#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Veiculos {
	string peso;
	string ano;
	string cor;
	string marca;
	
	public:
		void set_peso(string numero) {
			peso = numero;
		}
		
		string get_peso() {
			return peso;
		}
		
		void set_ano(string year) {
			ano = year;
		}
		
		string get_ano() {
			return ano;
		}
		
		void set_cor(string color) {
			cor = color;
		}
		
		string get_cor() {
			return cor;
		}
		
		void set_marca (string palavra) {
			marca = palavra;
		}
		
		string get_marca() {
			return marca;
		}
};

int main() {
	int menu = 0;
	string p, a, c, m;
	
	Veiculos v1;
	string cadastro;
	vector <string> cadastrador;
	vector <string>::iterator ponteiro;
	
	cout << "***** MENU *****" << endl;
	cout << "Digite 1 para adicionar um novo veiculo" << endl;
	cout << "Digite 2 para listar os veiculos ja listados" << endl;
	cout << "Digite 3 para sair do programa" << endl;
	cin >> menu;
	
	while (menu != 3) {
		
		if (menu == 1) {
			cout << "\nDigite o peso do carro: ";
			cin >> p;
			v1.set_peso(p);
			
			cout << "Digite o ano do carro: ";
			cin >> a;
			v1.set_ano(a);
			
			cout << "Digite a cor do carro: ";
			cin >> c;
			v1.set_cor(c);
			
			cout << "Digite a marca do carro: ";
			cin >> m;
			v1.set_marca(m);
			
			cadastro = "Peso: " + v1.get_peso() + "\n" + "Ano: " + v1.get_ano() + "\n" + "Cor: " + v1.get_cor() + "\n" + "Marca: " + v1.get_marca() + "\n\n";
			
			cadastrador.push_back(cadastro);
			
			ofstream account("cadastro.txt");
			for (ponteiro=cadastrador.begin(); ponteiro<cadastrador.end(); ponteiro++) {
				account << *ponteiro << endl;
			}
		}
		
		else if (menu == 2) {
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
		}
		
		cout << "\n\n***** MENU *****" << endl;
		cout << "Digite 1 para adicionar um novo veiculo" << endl;
		cout << "Digite 2 para listar os veiculos ja listados" << endl;
		cout << "Digite 3 para sair do programa" << endl;
		cin >> menu;
	}
	
	if (menu == 3)
		return 0;
	
	return 0;
}

#include <iostream>
using namespace std;

class Pessoa {
	string nome;
	
	public:
		void set_nome(string name) { 
			nome = name;
		}
		
		string get_nome() {
			return nome;
		}
};

class Empregado:public Pessoa {
	string cargo;
	
	public:
		void set_cargo(string funcao) {
			cargo = funcao;
		}
		
		string get_cargo() {
			return cargo;
		}
};

class Vendedor:public Empregado {
	double valorVendas, comissao;
	double salin, salt;
	
	public:
		void set_valorVendas(double vendidos) {
			valorVendas = vendidos;
		}
		
		double get_valorVendas() {
			return valorVendas;
		}
		
		double get_comissao() {
			return valorVendas * 0.15;
		}
		
		void set_salin(double salario_inicial) {
			salin = salario_inicial;
		}
		
		double get_salin() {
			return salin;
		}
		
		double get_salt() {
			return salin + get_comissao();
		}
};

int main() {
	Vendedor v1;
	
	v1.set_nome("Rodrigo");
	v1.set_cargo("Vendedor");
	v1.set_valorVendas(1230);
	v1.set_salin(500);
	
	cout << "\nNome do empregado: " << v1.get_nome() << endl;
	cout << "Cargo: " << v1.get_cargo() << endl;
	cout << "Quanto vendeu: " << v1.get_valorVendas() << endl;
	cout << "Valor da comissao: " << v1.get_comissao() << endl;
	cout << "Salario inicial: " << v1.get_salin() << endl;
	cout << "Salario total: " << v1.get_salt();
	
	return 0;
}

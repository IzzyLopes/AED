//Isabela Lopes - 190088940
// QUESTÃO 1 - FUNCIONÁRIO
#include <iostream>
#include <iomanip> //pra usar a função setprecision
using namespace std;

class Funcionario {
	string nome;
	double salario, vendasMes; //criei como double para pegar os valores depois da vírgula, caso necessário.
	double comissao, total;
	
	public:
		string get_nome() {
			return nome;
		}
		
		void set_nome(string novoNome){
			nome = novoNome;
		}
		
		double get_salario() {
			return salario;
		}
		
		void set_salario(double novoSalario) {
			salario = novoSalario;
		}
		
		double get_vendasMes() {
			return vendasMes;
		}
		
		void set_vendasMes(double novoVendas) {
			vendasMes = novoVendas;
		}
		
		double get_comissao() {
			return vendasMes * 0.05;
		}
		
		double get_total() {
			return salario + get_comissao();
		}
};

int main() {
	cout << setprecision(2) << fixed;  //coloquei pra garantir 2 casas decimais.
	
	string n1, n2, n3;
	double s1, s2, s3, v1, v2, v3;
	Funcionario f1, f2, f3;
	
	cout << "\t***** CALCULADOR DO SALARIO DOS FUNCIONARIOS *****" << endl;
	cout << "\nFuncionario 1:" << endl;
	cout << "Digite seu nome: ";
	cin >> n1;
	f1.set_nome(n1);
	
	cout << "Digite seu salario: ";
	cin >> s1;
	f1.set_salario(s1);
	
	cout << "Digite seu total de vendas: ";
	cin >> v1;
	f1.set_vendasMes(v1);
	
	cout << "\n\nFuncionario 2:" << endl;
	cout << "Digite seu nome: ";
	cin >> n2;
	f2.set_nome(n2);
	
	cout << "Digite seu salario: ";
	cin >> s2;
	f2.set_salario(s2);
	
	cout << "Digite seu total de vendas: ";
	cin >> v2;
	f2.set_vendasMes(v2);
	
	cout << "\n\nFuncionario 3:" << endl;
	cout << "Digite seu nome: ";
	cin >> n3;
	f3.set_nome(n3);
	
	cout << "Digite seu salario: ";
	cin >> s3;
	f3.set_salario(s3);
	
	cout << "Digite seu total de vendas: ";
	cin >> v3;
	f3.set_vendasMes(v3);
	
	system("cls");
	cout << "Funcionario 1:" << endl << "Nome: " << f1.get_nome() << endl << "Salario: " << f1.get_salario() << endl << "Total de vendas: " << f1.get_vendasMes() << endl << "Comissao: " << f1.get_comissao() << endl << "SALARIO TOTAL: " << f1.get_total() << endl;
	cout << "\nFuncionario 2:" << endl << "Nome: " << f2.get_nome() << endl << "Salario: " << f2.get_salario() << endl << "Total de vendas: " << f2.get_vendasMes() << endl << "Comissao: " << f2.get_comissao() << endl << "SALARIO TOTAL: " << f2.get_total() << endl;
	cout << "\nFuncionario 3:" << endl << "Nome: " << f3.get_nome() << endl << "Salario: " << f3.get_salario() << endl << "Total de vendas: " << f3.get_vendasMes() << endl << "Comissao: " << f3.get_comissao() << endl << "SALARIO TOTAL: " << f3.get_total() << endl;
	
	return 0; 
}

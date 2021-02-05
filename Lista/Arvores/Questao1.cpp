#include <iostream>
#include <locale.h>
#include <iomanip> // para usar o setprecision
#include <fstream> // para salvar no arquivo
#include <set>
using namespace std;

/* Isabela Lopes
Matricula - 190088940
Lista de Arvores - Questão 1 */

void menu() {
	cout << "Escolha uma opção:" << endl;
	cout << "1 - Inserir Notas" << endl;
	cout << "2 - Ordenar Notas" << endl;
	cout << "3 - Buscar Nota" << endl;
	cout << "4 - Apagar Nota" << endl;
	cout << "5 - Média da Turma" << endl;
	cout << "9 - Sair do Programa" << endl;
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	cout << setprecision(2) << fixed;
	
	set<double> arvore;
	
	int tamanho;
	cout << "Defina a quantidade de notas que serão guaradas na arvore" << endl;
	cin >> tamanho;

	cout << "\n";
	int in;
	menu();
	cin >> in;
	
	cout << "\n";
	system("pause");
	system("cls");
	
	while (in != 9) {
		double aux = 0.00;
			
		if (in == 1) {
			int qtd;
			cout << "Digite quantos valores serão inseridos:" << endl;
			cin >> qtd;
			
			if(qtd > tamanho) {
				cout << "A quantidade de valores inseridos não coincide com o tamanho da arvore." << endl;
				cout << "Digite novamente a quantidade de valores a ser inseridos" << endl;
				cin >> qtd;
			}
			
			for (int i=0; i<qtd; i++) {
				cout << "\nDigite a nota n° " << i+1 << endl;
				cin >> aux;
				arvore.insert(aux);
			}
		}
	
		else if (in == 2) { // Essa arvore já ordena sozinha
			cout << "\nA arvore ordenada ficou:" << endl;
			for (set<double>::iterator it=arvore.begin(); it != arvore.end(); it++) {
				cout << *it << endl;
			}
		}
		
		else if (in == 3) {
			cout << "\nDigite qual valor voce deseja buscar na arvore" << endl;
			cin >> aux;
			
			if (arvore.find(aux) != arvore.end()) {
				cout << "O valor " << aux << " foi encontrado.";
			}
			
			else {
				cout << "O valor " << aux << " não foi encontrado.";
			}
		}
		
		else if (in == 4) {
			cout << "\nDigite o valor a ser apagado" << endl;
			cin >> aux;
			
			arvore.erase(aux);
		}
		
		else if (in == 5) {
			double soma;
			for (set<double>::iterator it=arvore.begin(); it != arvore.end(); it++) {
				soma = soma + *it;
				cout << *it << " + ";
			}
			cout << " = " << soma;
			cout << "\nO tamanho da arvore é: " << arvore.size() << endl;
			
			cout << "\nA soma " << soma << " dividida pelo tamanho da arvore " << arvore.size() << " é igual a: " << soma/arvore.size();
		}
		
		else {
			cout << "Entrada indisponível, tente novamente\n" << endl;
			menu();
			cin >> in;
		}
		
		ofstream account("Notas.txt"); // Salvar no arquivo
		for (set<double>::iterator it=arvore.begin(); it != arvore.end(); it++) {
			account << *it << endl;
		}
		
		cout << "\n";
		system("pause");
		system("cls");
		menu();
		cin >> in;
	}
	
	return 0;
}

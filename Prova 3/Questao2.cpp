/* Universidade de Brasília
   Isabela Lopes - 190088940

   PROVA 3 DE AED
    Questao 2 */
    
#include <iostream>
#include <locale.h>
#include <list>
using namespace std;

int main() {
	setlocale (LC_ALL, "Portuguese");
	
	list<string> alunos;
	list<string>::iterator ganhador;
	
	int qtd_alunos;
	cout << "\nDigite quantos alunos tem na classe: "; // Letra A
	cin >> qtd_alunos;
	
	cout << "\n\nDigite o número do aluno + Nome do aluno \n\tExemplo: 1 - Isabela \n\t\t 2 - Helena" << endl;
	cout << "Obs: separando os alunos por enter.\n" << endl;
	string nomes = "";
	
	for (int i=0; i<qtd_alunos+1; i++) { // Letra A
		getline(cin, nomes);
		alunos.push_front(nomes);
	}
	
	alunos.sort();
	
	int sorteio;
	cout << "\n\tDigite qual o número sorteado: "; // Letra B
	cin >> sorteio;
	
	ganhador = alunos.begin();
	for (int i=0; i<sorteio; i++) {
		ganhador++;
	}
	
	system("pause");
	system("cls");
	
	cout << "\n\tO aluno sorteado foi:" << endl; // Letra C
	cout << *ganhador;
	
	return 0;
}

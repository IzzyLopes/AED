/* Universidade de Bras�lia
   Isabela Lopes - 190088940

   PROVA 3 DE AED
    Questao 3 */
    
#include <iostream>
#include <locale.h>
#include <list>
using namespace std;

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	list <int> pessoas;
	list <int>::iterator contador;
	list <int>::iterator morre;
	list <int>::iterator vivos;
	
	int qtd;
	cout << "\nDigite a quantidade de pessoas que est�o no c�rculo" << endl; // Letra A
	cin >> qtd;
	
	for (int i=1; i<=qtd; i++) {
		pessoas.push_front(i);
	}
	
	int intervalo;
	cout << "\nDigite o intervalo de pessoas a serem mortas" << endl; // C
	cin >> intervalo;
	
	int direcao;
	cout << "\nDeseja come�ar a matan�a pela: \n1 - Direita \n2 - Esquerda\n" << endl; // B
	cin >> direcao;
	
	if (direcao == 1) { // pela direita
		contador = pessoas.begin();
		while(pessoas.size() != 1) {
			int alive = pessoas.size();
			
			if(alive <= intervalo) { // Obs da quest�o
				cout << "\n\nDefina um intervalo menor que o numero de pessoas no c�rculo" << endl;
				cout << "Existem " << alive << " pessoas vivas." << endl;
				cin >> intervalo;
			}
			
			for (int i=0; i<intervalo; i++) {
				contador++;
			}
			
			contador++;
			morre = contador;
			morre = pessoas.erase(morre);
			
			cout << "\nPessoas que ainda est�o vivas:" << endl; // D
			for (vivos = pessoas.begin(); vivos != pessoas.end(); vivos++) {
				cout << " - " << *vivos;
			}
		}
	}
	
	else if (direcao == 2) { // pela esquerda
		contador = pessoas.end();
		while(pessoas.size() != 1) {
			int alive = pessoas.size();
			
			if(alive < intervalo) { // Obs da quest�o
				cout << "\n\nDefina um intervalo menor que o numero de pessoas no c�rculo" << endl;
				cout << "Existem " << alive << " pessoas vivas." << endl;
				cin >> intervalo;
			}
			
			for (int i=0; i<intervalo; i++) {
				contador--;
			}
			
			contador++;
			morre = contador;
			morre = pessoas.erase(morre);
			
			cout << "\nPessoas que ainda est�o vivas:" << endl; // D
			for (vivos = pessoas.end(); vivos != pessoas.begin(); vivos--) {
				cout << " - " << *vivos;
			}
		}
	}
	
	else {
		system("cls");
		cout << "\nEntrada inv�lida" << endl;
		cout << "\nDeseja come�ar a matan�a pela: \n1 - Direita \n2 - Esquerda\n" << endl;
		cin >> direcao;
	}
	
	return 0;
}

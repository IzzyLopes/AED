#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <locale.h>
using namespace std;

/* QUESTÃO 4
	Isabela Lopes
	190088940 */
	
int main() {
	setlocale(LC_ALL, "Portuguese");
	cout << setprecision(2) << fixed;
	srand(time(NULL));
	
	double alturas[100];
	
	cout << "As alturas dos alunos são:" << endl;
	for (int i=0; i<100; i++) {
		double high = (((double) 1 + rand() * 2) / RAND_MAX) + 1;
		alturas[i] = high;
		cout << alturas[i] << endl;
	}
	
	cout << "\n";
	system ("pause");
	system ("cls");
	
	double aux;
	bool continua, troca;
	continua = true;
	
	while (continua == true) {
		troca = false;
		
		for (int i=0; i<99; i++) {
			if (alturas[i] > alturas[i+1]) {
				aux = alturas[i+1];
				alturas[i+1] = alturas[i];
				alturas[i] = aux;
				troca = true;
			}
		}
		
		if(troca == false) {
			continua = false;
		}
	}
	
	cout << "O vetor ordenado ficou assim:" << endl;
	for (int i=0; i<100; i++) {
		cout << alturas[i] << endl;
	}
	
	return 0;
}

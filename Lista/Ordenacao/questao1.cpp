#include <iostream>
#include <locale.h>
#include <algorithm>
using namespace std;

/* QUESTÃO 1
	Isabela Lopes
	190088940 */

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int n;
	cout << "Digite o tamanho da lista: ";
	cin >> n;
	
	string lista[n];
	
	string nomes;
	for (int i=0; i<n; i++) {
		cout << "\nDigite o nome a ser colocado na lista na posição " << i+1 << "." << endl;
		cin >> nomes;
		lista[i] = nomes;
	}
	
	system("pause");
	system("cls");
	
	sort (lista, lista+n);
	
	for (int i=0; i<n; i++) {
		cout << lista[i] << endl;
	}
	return 0;
}

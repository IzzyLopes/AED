#include <iostream>
#include <locale.h>
using namespace std;

/* QUESTÃO 5
	Isabela Lopes
	190088940 */
	
int main() {
	setlocale(LC_ALL, "Portuguese");
	int n;
	cout << "Digite a quantidade n de nomes" << endl;
	cin >> n;
	
	string name;
	string nomes[n];
	
	
	for (int i=0; i<n; i++) {
		cout << "\nDigite o " << i+1 << "° nome." << endl;
		cin >> name;
		nomes[i] = name;
	}
	
	system("pause");
	system("cls");
	
	string aux;
	int min;
	
	for (int i=0; i<n-1; i++) {
		min = i;
		
		for (int j=i+1; j<n; j++) {
			if(nomes[j].size() < nomes[min].size()) {
				min = j;
			}
		}
		
		if (i != min) {
			aux = nomes[i];
			nomes[i] = nomes[min];
			nomes[min] = aux;
		}
	}
	
	cout << "Os nomes ordenados pelo tamanho ficaram assim:" << endl;
	for (int i=0; i<n; i++) {
		cout << nomes[i] << endl;
	}
	
	return 0;
}

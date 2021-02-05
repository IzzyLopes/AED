#include <iostream>
#include <locale.h>
#include <list>
using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	list <int> lista1;
	list <int>::iterator it;
	
	list <int> lista2;
	list <int>::iterator et;
	
	cout << "Lista 1:" << endl;
	for(int i=10; i>0; i--) {
		lista1.push_front(i);
		cout << lista1.front() << endl;
	}
	
	cout << "\nLista 2:" << endl;
	for (int i=11; i<21; i++) {
		lista2.push_front(i);
		cout << lista2.front() << endl;
	}
	
	
	// LETRA A - VERIFIQUE SE AS LISTAS ESTÃO ORDENADAS
	bool ordenado1;
	for (it=lista1.begin(); it!=lista1.end(); it++) {
		lista1.sort();
		
		if(*it != lista1.front()) {
			ordenado1 = false;
		}
		
		else
			ordenado1 = true;
	}
	
	if (ordenado1 == false)
		cout << "\nA lista 1 não está ordenada." << endl;
	
	else
		cout << "\nA lista 1 está ordenada." << endl;
	
	
	bool ordenado2;
	for (et=lista2.begin(); et!=lista2.end(); et++) {
		lista2.sort();
		
		if(*et == lista2.front()) {
			ordenado2 = true;
		}
		
		else
			ordenado2 = false;
	}
	
	if (ordenado2 == true)
		cout << "A lista 2 está ordenada." << endl;
	
	else
		cout << "A lista 2 não está ordenada." << endl;
	
	return 0;
}

#include <iostream>
using namespace std;

/* QUESTÃO 2
	Isabela Lopes
	190088940 */
	
int main () {
	string palavra;
	
	cout << "\n Digite uma palavra\n ";
	cin >> palavra;
	
	int pivot, parede, troca;
	
	parede = 0;
	pivot = palavra.size()+1;
	troca = 0;
	
	// Lógica de organizar em ordem descrescente
	while (pivot != 0) {
		for (int i=0; i<palavra.size(); i++) {
			if ((palavra[pivot] > palavra[i]) && (pivot > i)) {
				swap(palavra[i], palavra[pivot]);
				parede++;
			}
		
			troca++;
		}
		
		if (troca >= pivot) {
			pivot--;
		}
		
		if(troca < pivot) {
			swap(palavra[pivot], palavra[parede]);
		}
	}
	
	cout << endl;
	system("pause");
	cout << "\n " << palavra;
	
	return 0;
}

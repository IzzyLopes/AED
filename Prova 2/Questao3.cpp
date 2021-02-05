/* Universidade de Brasília
   Isabela Lopes - 190088940

   PROVA 2 DE AED
    Questao 3 */
    
#include<iostream>
using namespace std;

int main() {
	int vetor[10];
	int valores;
	
	// Letra A
	for (int i=0; i<10; i++) {
		cout << "Digite os valores para a posicao " << i+1 << " do vetor." << endl;
		cin >> valores;
		vetor[i] = valores;
	}
	
	int aux;
	for (int i=0; i<10; i++) { //Logica de ordenar por ordem crescente
		for (int j=i; j<10; j++) {
			if(vetor[i] > vetor[j]) {
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}	
	}
	
	cout << "\n\nO vetor ordenado crecentemente ficou assim: \n" << endl;
	for (int i=0; i<10; i++) {
		cout << vetor[i] << endl;
	}
	
	cout << "\n";
	system("pause");
	system("cls");
	
	// Letra B
	int n, posicao;
	int contador = 0;
	cout << "Agora vamos fingir que voce esqueceu se colocou determinado valor no vetor.\nVamos usar uma busca sequencial para procurar esse valor." << endl;
	cout << "Digite o valor que deseja procurar: ";
	cin >> n;
	
	int L = 0;
	int R = 9; // R = tamanho do vetor - 1 (10 - 1 = 9)
	int m;
	bool achou = false;
	
	if((R-L)%2 == 1) {
		m = ((R-L)/2);
	}
		
	else {
		m = ((R-L+1)/2);
	}
	
	while(achou == false) {
		contador = contador + 1;
		
		cout << "\n";
		for (int i=0; i<10; i++) {
			cout << "[ " << vetor[i] << " ]";
			
			if(i==L) {
				cout << "<--L";
			}
			
			if(i==R) {
				cout << "<--R";
			}
			
			if(i==m) {
				cout << "<--m";
			}
			
			cout << endl;
		}
		
		if(vetor[m] < n) {
			L = m+1;
		}
		
		else if (vetor[m] > n){
			R = m;
		}
		
		else {
			posicao = m + 1;
			achou = true;
		}
		
		if((R-L)%2 == 1) {
			m = ((R-L)/2) + L;
		}
		
		else {
			m = ((R-L+1)/2) + L;
		}
			
		if(L == R && L == m && R == m && vetor[m] == n) {
			posicao = m + 1;
			achou = true;
		}
		
		else if (L == R && L == m && R == m && vetor[m] != n) {
			posicao = -1;
			break;
		}
		
		system("PAUSE");
	}
	
	// Letra C
	if(achou == true) {
		cout << "\nO numero " << n << " foi encontrado na posicao " << posicao << "." << endl;
	}
	
	else {
		cout << "Posicao: " << posicao;
		cout << "\nO numero " << n << " nao foi encontrado." << endl;
 	}
	
	cout << "Foram feitas " << contador << " pesquisas." << endl;
	
	
	return 0;
}

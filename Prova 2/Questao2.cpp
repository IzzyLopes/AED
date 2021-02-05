/* Universidade de Brasília
   Isabela Lopes - 190088940

   PROVA 2 DE AED
    Questao 2 */
    
#include<iostream>
using namespace std;

int main () {
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
	int sentinela = 9; // sentinela == ao tamanho do vetor -1, que siginifica a ultima posição do vetor e sabemos que o tamanho desse vetor é 10
	int contador = 0;
	cout << "Agora vamos fingir que voce esqueceu se colocou determinado valor no vetor.\nVamos usar uma busca sequencial para procurar esse valor." << endl;
	cout << "Digite o valor que deseja procurar: ";
	cin >> n;
	
	for (int i=0; i != sentinela; i++) {
		contador = contador + 1;
			
		if (vetor[sentinela] == n) {
			posicao = sentinela + 1;
			break;
		}
		
		if (vetor[i] == n) {
			posicao = i + 1;
			break;
		}
		
		else if (vetor[i] != n) {
			posicao = -1;
		}
	}
	
	// Letra C
	if(posicao != -1) {
		cout << "\nO numero " << n << " foi encontrado na posicao " << posicao << "." << endl;
	}
	
	else {
		cout << "\nPosicao: " << posicao;
		cout << "\nO numero " << n << " nao foi encontrado." << endl;
 	}
	
	cout << "Foram feitas " << contador << " pesquisas." << endl;
	
	return 0;
}

/* Universidade de Brasília
   Isabela Lopes - 190088940

   PROVA 2 DE AED
    Questao 4 */
    
#include<iostream>
using namespace std;

void preencher(int v[]) {
	v[0] = 5;
	v[1] = 9;
	v[2] = 7;
	v[3] = 1;
	v[4] = 3;
	v[5] = 4;
	v[6] = 6;
	v[7] = 8;
	v[8] = 0;
	v[9] = 2;
}

int main() {
	int vet[10];
	int contseq = 0;
	preencher(vet);
	
	int aux;
	for (int i=0; i<10; i++) { // Já vou deixar o vetor ordenado pq todos os programas ordenam-o
		for (int j=i; j<10; j++) {
			if(vet[i] > vet[j]) {
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}	
	}
	
	// Busca Linear
	int posicao;
	cout << "Vamos implementar o vetor vet na Questao 1.\nQue utiliza a busca sequencial." << endl;
	cout << "O valor a ser buscado no vetor vai ser o numero 2." << endl;
	int n = 2;
	
	cout << "\n\nO vetor vet \n" << endl;
	for (int i=0; i<10; i++) {
		cout << vet[i] << endl;
	}

	
	for (int i=0; i<10; i++) {
		contseq = contseq + 1;
		
		if (vet[i] == n) {
			posicao = i + 1;
			break;
		}
		
		else if (vet[i] != n) {
			posicao = -1;
		}
	}
	
	if(posicao != -1) {
		cout << "\nO numero " << n << " foi encontrado na posicao " << posicao << "." << endl;
	}
	
	else {
		cout << "\nPosicao: " << posicao;
		cout << "\nO numero " << n << " nao foi encontrado." << endl;
 	}
	
	cout << "Foram feitas " << contseq << " pesquisas." << endl;
	
	cout << "\n";
	system("pause");
	system("cls");
	
	// Busca com Sentinela
	cout << "Vamos implementar o vetor vet na Questao 2.\nQue utiliza a busca com sentinela." << endl;
	cout << "O valor a ser buscado no vetor vai ser o numero 2." << endl;
	
	cout << "\n\nO vetor vet: \n" << endl;
	for (int i=0; i<10; i++) {
		cout << vet[i] << endl;
	}
	
	posicao = 0;
	int sentinela = 9;
	int contsentinela = 0;
	
	for (int i=0; i != sentinela; i++) {
		contsentinela = contsentinela + 1;
			
		if (vet[sentinela] == n) {
			posicao = sentinela + 1;
			break;
		}
		
		if (vet[i] == n) {
			posicao = i + 1;
			break;
		}
		
		else if (vet[i] != n) {
			posicao = -1;
		}
	}
	
	if(posicao != -1) {
		cout << "\nO numero " << n << " foi encontrado na posicao " << posicao << "." << endl;
	}
	
	else {
		cout << "\nPosicao: " << posicao;
		cout << "\nO numero " << n << " nao foi encontrado." << endl;
 	}
	
	cout << "Foram feitas " << contsentinela << " pesquisas." << endl;
	
		cout << "\n";
		system("pause");
		system("cls");
	
	// Busca Binária
	cout << "Vamos implementar o vetor vet na Questao 3.\nQue utiliza a busca binaria." << endl;
	cout << "O valor a ser buscado no vetor vai ser o numero 2." << endl;
	
	cout << "\n\nO vetor vet: \n" << endl;
	for (int i=0; i<10; i++) {
		cout << vet[i] << endl;
	}
	
	int contbin = 0;
	posicao = 0;
	
	int L = 0;
	int R = 9;
	int m;
	bool achou = false;
	
	if((R-L)%2 == 1) {
		m = ((R-L)/2);
	}
		
	else {
		m = ((R-L+1)/2);
	}
	
	while(achou == false) {
		contbin = contbin + 1;
		
		cout << "\n";
		for (int i=0; i<10; i++) {
			cout << "[ " << vet[i] << " ]";
			
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
		
		if(vet[m] < n) {
			L = m+1;
		}
		
		else if (vet[m] > n){
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
			
		if(L == R && L == m && R == m && vet[m] == n) {
			posicao = m + 1;
			achou = true;
		}
		
		else if (L == R && L == m && R == m && vet[m] != n) {
			posicao = -1;
			break;
		}
		
		system("PAUSE");
	}

	if(achou == true) {
		cout << "\nO numero " << n << " foi encontrado na posicao " << posicao << "." << endl;
	}
	
	else {
		cout << "Posicao: " << posicao;
		cout << "\nO numero " << n << " nao foi encontrado." << endl;
 	}
	
	cout << "Foram feitas " << contbin << " pesquisas." << endl;
	
	cout << "\n";
	system("pause");
	system("cls");
	
	cout << "\nAs informacoes que obtemos foram:" << endl;
	cout << "Pesquisa sequencial: " << contseq << endl;
	cout << "Pesquisa com sentinela: " << contsentinela << endl;
	cout << "Pesquisa binaria: " << contbin << endl;
	
	cout << "\nCom essas informacoes podemos afirmar que: " << endl;
	
	int ordem[2];
	ordem[0] = contseq;
	ordem[1] = contsentinela;
	ordem[2] = contbin;
	
	aux = 0;
	for (int i=0; i<2; i++) {
		for (int j=i; j<2; j++) {
			if(ordem[i] > ordem[j]) {
				aux = ordem[i];
				ordem[i] = ordem[j];
				ordem[j] = aux;
			}
		}	
	}
	
	// Mais buscas
	if (ordem[0] == contseq) {
		cout << "A Questao 1 (Busca Sequencial) fez mais buscas."  << endl;
	}
	
	else if (ordem[0] == contsentinela) {
		cout << "A Questao 2 (Busca com Sentinela) fez mais buscas." << endl;
	}
	
	else {
		cout << "A Questao 3 (Busca Binaria) fez mais buscas." << endl;
	}
		
	// Menos buscas
	if (ordem[2] == contseq) {
		cout << "A Questao 1 (Busca Sequencial) fez menos buscas."  << endl;
	}
	
	else if (ordem[2] == contsentinela) {
		cout << "A Questao 2 (Busca com Sentinela) fez menos buscas." << endl;
	}
	
	else {
		cout << "A Questao 3 (Busca Binaria) fez menos buscas." << endl;
	}
	
	cout << "\nA explicacao se deve ao tamanha do vetor.\nQuanto maior o vetor, mais eficiente sera a busca binaria." << endl;
	cout << "\nA busca sequencial funciona muito bem para vetores pequenos." << endl;
	cout << "\nA busca com sentinela funciona mto bem para veotres de tamanho indeterminado tambem.\nQue precisam que a partir de certo valor nao se leia mais o vetor." << endl;
	return 0;
}

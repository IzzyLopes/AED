#include <iostream>
#include <locale.h>
#include <list>
using namespace std;

/* QUESTÃO 1
	Isabela Lopes
	190088940 */

class Lista {
	list <int> questao1;
	list <int>::iterator ponteiro;
	
	public:
		int verificao (int valor) {
			int achou = 0;
			for (ponteiro = questao1.begin(); ponteiro != questao1.end(); ponteiro++) {
				if(*ponteiro == valor) {
					achou++;
				}	
			}
			
			return achou;
		}
		
		void insercao_em_p (int posicao, int valor) { // A - inserção em uma posição aleatória
			ponteiro = questao1.begin();
			
			for (int i=0; i<posicao-1; i++) {
				ponteiro++;
			}
			
			questao1.insert(ponteiro, valor);
		}
		
		void insercao_no_begin (int valor) { // A - inserção no começo da lista
			questao1.push_front(valor);
		}
		
		void insercao_no_final (int valor) { // A - inserção no fim da lista
			questao1.push_back(valor);
		}
		
		void remocao_em_p (int posicao) { // B - remoção em uma posição aleatória
			ponteiro = questao1.begin();
			
			for(int i=0; i<posicao-1; i++) {
				ponteiro++;
			}
			
			questao1.erase(ponteiro);
		}
		
		void remocao_begin() { // B - remoção no começo da lista
			questao1.pop_front();
		}
		
		void remocao_end() { // B - remoção no fim da lista
			questao1.pop_back();
		}
		
		void remocao_com_busca (int valor) { // B - remoção de valor espeífico
			int i = 1;
			bool achou = false;
			for (ponteiro = questao1.begin(); ponteiro != questao1.end(); ponteiro++) {
				if(*ponteiro == valor) {
					achou = true;
				}
				
				i++;	
			}
			
			if(achou == false) {
				cout << "O valor " << valor << " não foi encontrado." << endl;
			}
			
			else {
				for(int j=0; j<i; j++) {
					ponteiro++;
				}
			
				questao1.erase(ponteiro);
			}
			
		}
		
		void busca (int valor) { // C - busca
			int i = 1;
			bool achou = false;
			for (ponteiro = questao1.begin(); ponteiro != questao1.end(); ponteiro++) {
				if(*ponteiro == valor) {
					cout << "O valor " << valor << " foi encontrado na posição " << i << endl;
					achou = true;
				}
				
				i++;	
			}
			
			if(achou == false) {
				cout << "O valor " << valor << " não foi encontrado." << endl;
			}
		}
		
		void exibir() { // D - Exibir a lista
			for (ponteiro = questao1.begin(); ponteiro != questao1.end(); ponteiro++) {
				cout << *ponteiro << endl;
			}
		}
		
};

void menu() {
		cout << "\n\t\t MENU \nOpções:" << endl;
		cout << "1 - Inserir" << endl;
		cout << "2 - Remover" << endl;
		cout << "3 - Buscar" << endl;
		cout << "4 - Exibir Lista" << endl;
		cout << "\n0 - Finalizar o programa" << endl;
		cout << "\nQual ação deseja fazer: ";
}

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	Lista Q1;
	
	int option;
	menu();
	cin >> option;
	
	while(option != 0) {
		int valor = 0;
		int posicao = 0;
		
		if (option == 1) {
			system("cls");
			cout << "\nDigite qual valor deseja inserir..." << endl;
			cin >> valor;
			
			if (Q1.verificao(valor) == 1) {
				cout << "\nO valor já existe na lista" << endl;
			}
			
			else {
				int caso1;
				cout << "\nDeseja inserir o valor em:" << endl;
				cout << "1 - Começo da lista \n2 - Fim da lista \n3 - Posição específica\n" << endl;
				cin >> caso1;
			
				if (caso1 == 1) {
					Q1.insercao_no_begin(valor);
				}
			
				else if (caso1 == 2) {
					Q1.insercao_no_final(valor);
				}
			
				else if (caso1 == 3) {
					cout << "\nEscolha a posição que o valor será inserido..." << endl;
					cin >> posicao;
					Q1.insercao_em_p(posicao, valor);
				}
			}
		}
		
		else if (option == 2) {
			system("cls");
			
			int caso2;
			cout << "\nDeseja remover o valor na posicao:" << endl;
			cout << "1 - Começo da lista \n2 - Fim da lista \n3 - Posição específica \n4 - Valor específico\n" << endl;
			cin >> caso2;
			
			if (caso2 == 1) {
				Q1.remocao_begin();
			}
			
			else if (caso2 == 2) {
				Q1.remocao_end();
			}
			
			else if (caso2 == 3) {
				cout << "\nEscolha a posição que o valor será removido..." << endl;
				cin >> posicao;
				Q1.remocao_em_p(posicao);
			}
			
			else if (caso2 == 4) {
				cout << "\nDigite o valor que deseja remover..." << endl;
				cin >> valor;
				Q1.remocao_com_busca(valor);
			}
		}
		
		else if (option == 3) {
			system("cls");
			
			cout << "\nDigite qual valor deseja buscar na lista..." << endl;
			cin >> valor;
			Q1.busca(valor);
		}
		
		else if (option == 4) {
			system("cls");
			
			Q1.exibir();
		}
		
		system("pause");
		system("cls");
		menu();
		cin >> option;
	}
	
	return 0;
}

#include <iostream>
#include <locale.h>
#include <list>
using namespace std;

/* QUESTÃO 2
	Isabela Lopes
	190088940 */

class No {
	public:
		string nome;
		string descricao;
		
		No *proximo;
		
		No() {
			this->proximo = NULL;
		};
		
		No(string name, string description) {
			this->nome = name;
			this->descricao = description;
			this->proximo = NULL;
		}
		
		string inserir_elemento(string newName, string newDescription) { // 1
			No *NewNo = new No(newName, newDescription);
			No *head = this->proximo;
	
			if(head == NULL) {
				NewNo->proximo = NewNo;
		
				head = NewNo;
				this->proximo = NewNo;
				return newName, newDescription;
			}
	
			No *aux = head;
	
			while (aux->proximo != head) {
				aux = aux->proximo;
			}
	
			aux->proximo = NewNo;
			NewNo->proximo = head;
		}
		
		
		void deletar_elemento (string remName) { // 2
			No *head = this->proximo;
			No *aux = head;
			No *anterior = NULL;
	
			while (aux->proximo != head) {
				if (aux->nome == remName) {
					break;
				}
			
				anterior = aux;
				aux = aux->proximo;
			}
	
			if (aux == head) {
				while (aux->proximo != head) {
					aux = aux->proximo;
				}
		
				aux->proximo = head->proximo;
				delete head;
		
				this->proximo = (aux->proximo);
				this->nome = (aux->nome);
				head = aux->proximo;
			}
	
			else {
				anterior->proximo = aux->proximo;
				delete aux;
			}
		}
		
		
		void mostrar() { // 3
			No *head = this->proximo;
			
			if(head) {
				No *tmp = head;
				
				while(tmp->proximo != head) {
					cout << tmp->nome << "\t";
					cout << tmp->descricao << "\t";
					tmp = tmp->proximo;
				}
				cout << tmp->nome << endl;
				cout << tmp->descricao << endl;
			}
		}
		
		void busca (string buscaNome) { // 4
			No *head = this->proximo;
			No *aux = head;
			No *anterior = NULL;
	
			while (aux->proximo != head) {
				if (aux->nome == buscaNome) {
					cout << "O tema " << buscaNome << " foi encontrado.";
					break;
				}
					
				anterior = aux; 
      			aux = aux->proximo;
			}
		}

};

void menu() {
	cout << "1 - Incluir um Tema" << endl;
	cout << "2 - Remover um Tema" << endl;
	cout << "3 - Navegar pelos Temas com opção para ver o próximo tema e o tema anterior." << endl;
	cout << "4 - Pesquisar um Tema pelo nome" << endl;
	cout << "5 - Sair do Programa" << endl;
	cout << "\nQual ação deseja fazer: ";
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	No inicio;
	int select;
	string nome, descricao;
	
	menu();
	cin >> select;
	
	while(select != 5) {
		if (select == 1) {
			cout << "Entre com o nome do tema a ser inserido, dê enter e descreva-o." << endl;
			cin >> nome;
			getline(cin, descricao);
			inicio.inserir_elemento(nome, descricao);
		}
		
		else if (select == 2) {
			cout << "Entre com o nome do Tema a ser removido" << endl;
			cin >> nome;
			descricao = "";
			inicio.deletar_elemento(nome);
		}
		
		else if (select == 3) {
			inicio.mostrar();
		}
		
		else if (select == 4) {
			cout << "Entre com o nome do Tema a ser procurado" << endl;
			cin >> nome;
			inicio.busca(nome);
		}
		
		system("pause");
		system("cls");
		menu();
		cin >> select;
	}
	
	return 0;
}

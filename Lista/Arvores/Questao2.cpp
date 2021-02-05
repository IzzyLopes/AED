#include <iostream>
#include <locale.h>
#include <set>
using namespace std;

/* Isabela Lopes
Matricula - 190088940
Lista de Arvores - Questão 2 */

struct library {
	string nome;
	int pag;
	int id;
	int ano;
};

void menu() {
	cout << "Escolha uma opção:" << endl;
	cout << "1 - Inserir Livros em cada ano" << endl;
	cout << "2 - Buscar Livro" << endl;
	cout << "3 - Sair do Programa" << endl;
	cout << "\n";
}

int main()  {
	setlocale(LC_ALL,"Portuguese");
	
	set<int> arv;
	library lib[100];
	
	int pag, id, ano, n;
	string nome;
	
	menu();
	cin >> n;
	
	if(n>3 || n<0) {
		cout << "\nEntrada inválida, tente novamente." << endl;
		cin >> n;
	}
	
	while(n != 3) {
		switch(n) {
			case 1:
				cout << "\nDigite a ID do livro:" << endl;
				cin >> id;
				
				cout << "\nDigite o nome do livro:" << endl;
				getline(cin, nome);
				getline(cin, nome);
				lib[id].nome = nome;
				
				cout << "\nDigite quantas páginas o livro têm:" << endl;
				cin >> pag;
				lib[id].pag = pag;
				
				cout << "\nDigite o ano de publicação do livro:" << endl;
				cin >> ano;
				lib[id].ano = ano;
				arv.insert(ano);
				break;
			
			case 2:
				cout << "\nQual o ano e a ID do livro que você gostaria buscar?" << endl;
				cin>>ano;
				cin>>id;
				
				if(arv.find(ano)!=arv.end()){
					cout << "\nO livro " << lib[id].nome <<", "<< lib[id].pag <<" páginas, foi encontrado." << endl;
				}
			
				else{
					cout<<"\nO livro não foi encontrado" << endl;
				}
				break;
			
			default:
				return 0;
		}
		
		cout << "\n";
		system("pause");
		system("cls");
		menu();
		cin >> n;
	}
}

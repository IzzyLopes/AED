#include <iostream>
#include <locale.h>
#include <set>
using namespace std;

/* Prova 4 de AED
Questão 1
Isabela Lopes
Matrícula: 190088940 */

class family{
	string nome;
	string idade;
	int ano;
	
	public:
		void set_nome(string name) {
			nome = name;
		}
		
		string get_nome() {
			return nome;
		}
		
		void set_idade(string age){
			idade = age;
		}
		
		string get_idade() {
			return idade;
		}
		
		void set_ano(int anos){
			ano = anos;
		}
		
		int get_ano() {
			return ano;
		}
};


void menu() {
	cout << "Escolha uma opção:" << endl;
	cout << "1 - Adicionar novo membro" << endl;
	cout << "2 - Excluir membro" << endl;
	cout << "3 - Mudar nome de membro" << endl;
	cout << "4 - Procurar por membro" << endl;
	cout << "5 - Nome do membro mais velho" << endl;
	cout << "6 - Nome do membro mais novo" << endl;
	cout << "0 - Sair do Programa" << endl;
	cout << "\n";
}


int main() {
	setlocale(LC_ALL, "Portuguese");
	
	family fam[100];
	set <string> arv;
	
	int n;
	menu();
	cin >> n;
	
	if(n>6 || n<0) {
		cout << "\nEntrada inválida. Tente novamente." << endl;
		cin >> n;
	}
	
	while(n != 0) {
		string nome;
		string idade;
		int ano;
		string cadastro[100];
		
		if(n == 1) {
			int qtd;
			cout << "\nQuantos membros deseja adicionar?" << endl;
			cin >> qtd;
				
			for(int i=0; i<qtd; i++) {
				cout << "\n\tMembro n° " << i+1 << endl;
				cout << "Nome: ";
				cin.ignore();
				getline(cin, nome);
				fam[i].set_nome(nome);
					
				cout << "Idade: ";
				cin >> ano;
				fam[i].set_ano(ano);
				
				cout << "\nEscreva por extenso.\n(Ex: 18 anos)" << endl;
				cin.ignore();
				getline(cin, idade);
				fam[i].set_idade(idade);
				
				cadastro[i] = fam[i].get_nome() + ", " + fam[i].get_idade() + "."; 
				arv.insert(cadastro[i]);
			}
		}
		
		else if(n == 2) {
			cout << "\nQual o nome e a idade do membro que deseja excluir" << endl;
			cout << "Nome: ";
			cin.ignore();
			getline(cin, nome);
			
			cout << "Idade: ";
			cin >> idade;
			
			string erase = nome + ", " + idade + " anos.";
			
			arv.erase(erase);
		}	
			
		else if(n == 3) {
			cout << "\nAntigo nome e idade do membro.\nNome: " << endl;
			cin.ignore();
			getline(cin, nome);
			
			cout << "Idade: ";
			cin >> idade;
			
			string newnome;
			cout << "\nNovo nome do membro" << endl;
			cin.ignore();
			getline(cin, newnome);
			
			string change = nome + ", " + idade + " anos.";
			string novo = newnome + ", " + idade + " anos.";
			int posicao = 0;
			for (int i=0; i<arv.size(); i++) {
				if(cadastro[i] == change) {
					swap(cadastro[i], novo);
				}
			}
		}
				
		else if(n == 4) {
			cout << "\nQual o nome e a idade do membro que deseja encontrar" << endl;
			cout << "Nome: ";
			cin.ignore();
			getline(cin, nome);
			
			cout << "Idade: ";
			cin >> idade;
			
			string search = nome + ", " + idade + " anos.";
			
			if (arv.find(search) != arv.end()) {
				cout << "O membro " << nome << " foi encontrado.";
			}
			
			else {
				cout << "O membro " << nome << " não foi encontrado.";
			}
		}
				
		else if(n == 5) {
			int oldest;
			int posicao = 0;
	
			for (int i=0; i<arv.size(); i++) {
				if(oldest < fam[i].get_ano()) {
					oldest = fam[i].get_ano();
					posicao = i;
				}
			}
				
			cout << "\nO membro mais velho se chama: " << fam[posicao].get_nome() << endl;
			cout << "Sua idade é: " << fam[posicao].get_idade();
		}
				
		else if(n == 6) {
			int newest;
			int posicao = 0;
				
			for(int i=0; i<arv.size(); i++) {
				if(fam[i].get_ano() < newest) {
					newest = fam[i].get_ano();
					posicao = i;
				}
			}
				
			cout << "\nO membro mais novo se chama: " << fam[posicao].get_nome() << endl;
			cout << "Sua idade é: " << fam[posicao].get_idade();
		}
		
		cout << "\n";
		system("pause");
		system("cls");
		
		cout << "\n\nA árvore está assim:" << endl;
		for(set<string>::iterator it=arv.begin(); it !=arv.end(); it++) {
			cout << *it << endl;
		}
		
		cout << "\n";
		menu();
		cin >> n;
	}
	
	return 0;
}

#include <iostream>
#include <locale.h>
#include <set>
using namespace std;

/* Prova 4 de AED
Questão 2
Isabela Lopes
Matrícula: 190088940 */

class Cars{
	string nome1;
	string nome2;
	string idade1;
	string idade2;
	int ano1;
	int ano2;
	
	public:
		void set_nome1(string name1) {
			nome1 = name1;
		}
		
		string get_nome1() {
			return nome1;
		}
		
		void set_nome2(string name2) {
			nome2 = name2;
		}
		
		string get_nome2() {
			return nome2;
		}
		
		// --------------------------------
		void set_idade1(string age1){
			idade1 = age1;
		}
		
		string get_idade1() {
			return idade1;
		}
		
		void set_idade2(string age2){
			idade2 = age2;
		}
		
		string get_idade2() {
			return idade2;
		}
		
		// ---------------------------------
		void set_ano1(int anos1){
			ano1 = anos1;
		}
		
		int get_ano1() {
			return ano1;
		}
		
		void set_ano2(int anos2){
			ano2 = anos2;
		}
		
		int get_ano2() {
			return ano2;
		}
};

void menu() {
	cout << "Escolha uma opção:" << endl;
	cout << "1 - Adicionar novo carro" << endl;
	cout << "2 - Excluir carro" << endl;
	cout << "3 - Procurar por carro" << endl;
	cout << "4 - Média de idade de todos os carros" << endl;
	cout << "5 - Carro com menos tempo de uso" << endl;
	cout << "6 - Carro com mais tempo de uso" << endl;
	cout << "0 - Sair do Programa" << endl;
	cout << "\n";
}


int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Cars car[100];
	set <string> arv1; // Para caros com tempo de uso menor que 10 anos
	set <string> arv2; // Para caros com tempo de uso maior que 10 anos
	
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
			cout << "\nQuantos carros deseja adicionar?" << endl;
			cin >> qtd;
				
			for(int i=0; i<qtd; i++) {
				cout << "\n\tCarro n° " << i+1 << endl;
				cout << "Tempo de uso em anos: ";
				cin >> ano;		
				
				if(ano <= 10) {
					car[i].set_ano1(ano);
					
					cout << "Nome: ";
					cin.ignore();
					getline(cin, nome);
					car[i].set_nome1(nome);
									
					cout << "\nEscreva o tempo de uso novamente" << endl;
					cin >> idade;
					car[i].set_idade1(idade);
				
					cadastro[i] = car[i].get_nome1() + ", " + car[i].get_idade1() + " anos."; 
					arv1.insert(cadastro[i]);
				}
				
				else {
					car[i].set_ano2(ano);
					
					cout << "Nome: ";
					cin.ignore();
					getline(cin, nome);
					car[i].set_nome2(nome);
									
					cout << "\nEscreva o tempo de uso novamente" << endl;
					cin >> idade;
					car[i].set_idade2(idade);
				
					cadastro[i] = car[i].get_nome2() + ", " + car[i].get_idade2() + " anos."; 
					arv2.insert(cadastro[i]);
				}
			}
		}
		
		else if(n == 2) {
			cout << "\nQual o nome e o tempo de uso do carro que deseja excluir" << endl;
			cout << "Nome: ";
			cin.ignore();
			getline(cin, nome);
			
			cout << "Tempo de uso: ";
			cin >> ano;
			
			cout << "\nEscreva o tempo de uso por extenso.\n(Ex: 18 anos)" << endl;
			cin.ignore();
			getline(cin, idade);
			
			string erase = nome + ", " + idade + ".";
			
			if (ano <= 10) {
				arv1.erase(erase);
			}
			
			else {
				arv2.erase(erase);
			}
		}	
			
		else if(n == 3) {
			cout << "\nQual o nome e o tempo de uso do carro que deseja encontrar" << endl;
			cout << "Nome: ";
			cin.ignore();
			getline(cin, nome);
			
			cout << "Tempo de uso: ";
			cin >> ano;
			
			cout << "\nEscreva o tempo de uso por extenso.\n(Ex: 18 anos)" << endl;
			cin.ignore();
			getline(cin, idade);
			
			string search = nome + ", " + idade + " anos.";
			
			if (ano <= 10) {
				if (arv1.find(search) != arv1.end()) {
					cout << "O carro " << nome << " foi encontrado.";
				}
			
				else {
					cout << "O carro " << nome << " não foi encontrado.";
				}
			}
			
			else {
				if (arv2.find(search) != arv2.end()) {
					cout << "O carro " << nome << " foi encontrado.";
				}
			
				else {
					cout << "O carro " << nome << " não foi encontrado.";
				}
			}
			
		}
				
		else if(n == 4) {
			int soma1, soma2;
			
			for(int i=0; i<arv1.size(); i++) {
				soma1 = soma1 + car[i].get_ano1();
			}
			
			for(int j=0; j<arv2.size(); j++) {
				soma2 = soma2 + car[j].get_ano2();
			}
			
			int somat = soma1 + soma2;
			int tamanho = arv1.size() + arv2.size();
			int media = somat / tamanho;
			
			cout << "\nA média de todos os carros é:" << endl;
			cout << media << " anos." << endl;

		}
				
		else if(n == 5) {
			int newest;
			int posicao = 0;
				
			for(int i=0; i<arv1.size(); i++) {
				if(car[i].get_ano1() < newest) {
					newest = car[i].get_ano1();
					posicao = i;
				}
			}
				
			cout << "\nO carro com menos tempo de uso é: " << car[posicao].get_nome1() << endl;
			cout << "Seu tempo de uso é: " << car[posicao].get_idade1();
		}
		
		else if(n == 6) {
			int oldest;
			int posicao = 0;
	
			for (int i=0; i<arv2.size(); i++) {
				if(oldest < car[i].get_ano2()) {
					oldest = car[i].get_ano2();
					posicao = i;
				}
			}
				
			cout << "\nO carro com mais tempo de uso é: " << car[posicao].get_nome2() << endl;
			cout << "Seu tempo de uso é: " << car[posicao].get_idade2();
		}
		
		cout << "\n";
		system("pause");
		system("cls");
		
		cout << "\n\nA árvore 1 está assim:" << endl;
		for(set<string>::iterator it=arv1.begin(); it!=arv1.end(); it++) {
			cout << *it << endl;
		}
		
		cout << "\n\nA árvore 2 está assim:" << endl;
		for(set<string>::iterator it=arv2.begin(); it!=arv2.end(); it++) {
			cout << *it << endl;
		}
		
		cout << "\n";
		menu();
		cin >> n;
	}
	
	return 0;
}


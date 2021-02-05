#include <iostream>
#include <queue>
using namespace std;

void menu() {
	cout << "Escolha uma opção:" << endl;
	cout << "1 - Inserir valor na fila" << endl;
	cout << "2 - Remover valor da fila" << endl;
	cout << "3 - Exibir o valor que está no topo da fila" << endl;
	cout << "4 - Limpar a fila" << endl;
	cout << "5 - Mostrar o tamanho da fila" << endl;
	cout << "6 - Exibir todos os elementos da fila" << endl;
	cout << "7 - Exibir todos os elementos da fila na ordem inversa" << endl;
	cout << "8 - Exibir apenas os elementos ímpares" << endl;
	cout << "9 - Inverter todos os elementos da fila" << endl;
	cout << "0 / 10 - Sair do Programa" << endl;
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	queue <int> fila;
	
	int in;
	menu();
	cin >> in;
	
	if (in<0 || in>10) {
		cout << "\nEntrada inválida. Tente novamente" << endl;
		cin >> in;
	}
	
	while(in!=0 || in!=10) {
		int valor = 0;
		
		switch(in) {
			case 1:
				cout << "\nDigite qual valor deseja inserir na fila" << endl;
				cin >> valor;
				fila.push(valor);
				break;
				
			case 2:
				fila.pop();
				cout << fila;
				break;
			
			case 3:
				cout << fila.front();
				break;
				
			case 4:
				fila.clear();
				break;
				
			case 5:
				cout << "O tamanho da fila é: " << fila.size();
				break;
			
			case 6:
				cout << fila.print() << endl;
				break;
				
			case 7:
				cout << fila.inverter() << endl;
				break;
				
			case 8:
				for(int i=0; i<fila.size(); i++) {
					if(i%2 != 0) {
						cout << fila[i];
					}
				}
				break;
			
			case 9:
				fila.inverter();
				
			default:
				return 0;
 		}
 		
 		cout << "\n";
		system("pause");
		system("cls");
		menu();
		cin >> in;
	}
	
	return 0;
}

/* 
QUESTÃO 1218 - Getline Three - Calçados

Agora que Mangojata resolveu alguns problemas que utilizavam getline, acha que está apta a dar um passo adiante.
Ela está prestes a fazer um novo programa para auxiliar a sua irmã, Overlaine. Overlaine é vendedora de calçados e por um acidente, misturou todos os pares de calçados que tinha para vender.
Ela quer informar um número qualquer N e contar quantos calçados de uma determinada caixa são deste tamanho (N). 
O problema é que Overlaine não tem a menor idéia de quantos calçados existem em cada caixa.
A única coisa que sabe é que cada calçado pode ter numeração de 20 a 44, podendo ser masculino ou feminino.

Entrada
A entrada contém vários casos de teste e termina com EOF (Fim de Arquivo).
Cada caso de teste consiste de duas linhas de entrada.
A primeira linha contém uma numeração N (20 = N = 44) de calçado que Overlaine informa e a segunda linha contém o número de cada par que está dentro da caixa seguido de M ou F,
indicando se o par é de calçado Masculino ou Feminino.

Saída
Para cada caso de teste imprima quatro linhas, conforme exemplo abaixo.
A primeira linha deve apresentar a mensagem “Caso n:”, onde n é o número do caso de teste.
A segunda linha deve informar quantos pares da caixa de calçados são iguais ao número que Overlaine quer encontrar, com mensagem correspondente.
Seguem duas linhas com a quantidade respectiva de calçados Femininos (F) e Masculinos (M), com mensagem correspondente.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Numeracao {
	string sapato;
	
	public:
		string get_sapato() {
			int box = rand() % 24;
			
			if (box == 0)
				sapato = "20";
			
			else if (box == 1)
				sapato = "21";
			
			else if (box == 2)
				sapato = "22";
			
			else if (box == 3)
				sapato = "23";
				
			else if (box == 4)
				sapato = "24";
				
			else if (box == 5)
				sapato = "25";
			
			else if (box == 6)
				sapato = "26";
			
			else if (box == 7)
				sapato = "27";
			
			else if (box == 8)
				sapato = "28";
			
			else if (box == 9)
				sapato = "29";
			
			else if (box == 10)
				sapato = "30";
				
			else if (box == 11)
				sapato = "31";
			
			else if (box == 12)
				sapato = "32";
			
			else if (box == 13)
				sapato = "33";
			
			else if (box == 14)
				sapato = "34";
			
			else if (box == 15)
				sapato = "35";
			
			else if (box == 16)
				sapato = "36";
			
			else if (box == 17)
				sapato = "37";
				
			else if (box == 18)
				sapato = "38";
			
			else if (box == 19)
				sapato = "39";
			
			else if (box == 20)
				sapato = "40";
			
			else if (box == 21)
				sapato = "41";
			
			else if (box == 22)
				sapato = "42";
			
			else if (box == 23)
				sapato = "43";
			
			else if (box == 24)
				sapato = "44";
			
			return sapato;
		}
};

class Caixa:public Numeracao{
	string sexo;
	
	public:
		string get_sexo() {
			int sex = rand() % 2;
			
			if (sex == 1) 
				sexo = "M"; // Masculino
		
			if (sex == 0)
				sexo = "F"; // Feminino
				
			return sexo;
		}
};

int main() {
	srand(time(NULL));
	Caixa c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
	
	string espaco = c1.get_sapato()+c1.get_sexo() + " " + c2.get_sapato()+c2.get_sexo() + " " + c3.get_sapato()+c3.get_sexo() + " " + c4.get_sapato()+c4.get_sexo() + " " + c5.get_sapato()+c5.get_sexo() + " " + c6.get_sapato()+c6.get_sexo() + " " + c7.get_sapato()+c7.get_sexo() + " " + c8.get_sapato()+c8.get_sexo() + " " + c9.get_sapato()+c9.get_sexo() + " " + c10.get_sapato()+c10.get_sexo();
	
	vector <string> shoes;
	vector <string>::iterator ponteiro;
	vector <string>::iterator procura;
	
	shoes.push_back(espaco);
	
	ofstream caixas("caixas.txt"); // Salvar arquivo
	for (ponteiro=shoes.begin(); ponteiro<shoes.end(); ponteiro++) {
		caixas << *ponteiro << endl;
	}
	
	ifstream boxes("caixas.txt"); // Abrir arquivo
	shoes.clear();
	string arquivo;
	
	if(boxes.is_open()) {
		while(! boxes.eof()) {
			getline (boxes, arquivo);
			shoes.push_back(arquivo);
		}
		boxes.close();
	}
	
	string n;
	cout << "Digite qual a numeracao de sapato que voce deseja: ";
	cin >> n;
	
	system("cls");
	
	for (ponteiro=shoes.begin(); ponteiro<shoes.end(); ponteiro++){
		cout << *ponteiro;
	}
		
	string guardar;
	for (procura = shoes.begin(); procura < shoes.end(); procura++) {
		guardar = *procura;
		int pares = 0;
		size_t pares_iguais = guardar.find(n);
		
		if (pares_iguais != std::string ::npos) {
			pares_iguais = guardar.find(n, pares_iguais + 1);
			pares++;
		}
		
		else{
			pares = 0;
		}
		
		string femme = n + "F";
		int feminino = 0;
		size_t contf = guardar.find(femme);
		
		if (contf != std::string::npos) {
			contf = guardar.find(femme, contf + 1);
			feminino++;
		}
		
		else {
			feminino = 0;
		}
		
		string homme = n + "M";
		int masculino = 0;
		size_t contm = guardar.find(homme);
		
		if (contm != std::string::npos) {
			contm = guardar.find(homme, contm + 1);
			masculino++;
		}
		
		else {
			masculino = 0;
		}
		
		cout << "\n\nCaso " << n << ":"	<< endl;
		cout << "Pares Iguais: " << pares << endl;
		cout << "F: " << feminino << endl;
		cout << "M: " << masculino;
		break;
	}

	return 0;
}

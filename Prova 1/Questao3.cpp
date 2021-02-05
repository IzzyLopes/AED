//Isabela Lopes - 190088940
// QUESTÃO 3 - LANCHONETE
#include <iostream>
using namespace std;

class Lanchonete {
	double total; //Valor total com impostos
	
	public:
		double get_total() {
			return total;
		}
		
		void set_total(double value) {
			total = value + (value*0.05);
		}
};

class Pizza:public Lanchonete {
	double precoP, qtdCalP;
	
	public:
		void set_precoP(double priceP) {
			precoP = priceP;
		}
		
		double get_precoP() {
			return precoP;
		}
		
		void set_qtdCalP(double novoQtdP) {
			qtdCalP = novoQtdP;
		}
		
		double get_qtdCalP() {
			return qtdCalP;
		}
};

class Hamburguer:public Lanchonete {
	double precoH, qtdCalH;
	
	public:
		void set_precoH(double priceH) {
			precoH = priceH;
		}
		
		double get_precoH() {
			return precoH;
		}
		
		void set_qtdCalH(double novoQtdH) {
			qtdCalH = novoQtdH;
		}
		
		double get_qtdCalH() {
			return qtdCalH;
		}
};

int main() {
	Pizza p1;
	p1.set_precoP(40);
	p1.set_qtdCalP(266);
	p1.set_total(40);
	
	Hamburguer h1;
	h1.set_precoH(25);
	h1.set_qtdCalH(295);
	h1.set_total(25);
	
	cout << "Opcao 1: PIZZA, R$ " << p1.get_precoP() << ", mas com os impostos fica: R$" << p1.get_total() << " - CALORIAS: " << p1.get_qtdCalP() << " cal." << endl;
	cout << "Opcao 2: HAMBURGUER, R$ " << h1.get_precoH() << ", mas com os impostos fica: R$" << h1.get_total() << " - CALORIAS: " << h1.get_qtdCalH() << " cal." << endl;
	
	if (p1.get_total() > h1.get_total()){
		cout << "\nO lanche mais caro do cardapio: PIZZA" << endl;
	}
	
	else {
		cout << "\nO lanche mais caro do cardapio: HAMBURGUER" << endl;
	}
	
	if (p1.get_qtdCalP() > h1.get_qtdCalH()) {
		cout << "\nO lanche mais calorico do cardapio: PIZZA" << endl;
	}
	
	else {
		cout << "\nO lanche mais calorico do cardapio: HAMBURGUER" << endl;
	}
	
	return 0;
}

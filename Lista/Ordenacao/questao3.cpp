#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;

/* QUESTÃO 3
	Isabela Lopes
	190088940 */
	
struct Pessoa {
	int Matricula;
	char Nome[30];
	float Nota;
};

// Pela matricula
void merge_int (struct Pessoa *V, int left, int middle, int right) {
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	struct Pessoa L[n1], R[n2];
	
	for (i=0; i<n1; i++) {
		L[i] = V[left + i];
	}
	
	for (j=0; j<n2; j++) {
		R[j] = V[middle + j + 1];
	}
	
	i = 0;
	j = 0;
	k = left;
	
	while (i<n1 && j<n2) {
		if(L[i].Matricula <= R[j].Matricula) {
			V[k] = L[i];
			i++;
		}
		
		else {
			V[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	while (i < n1) {
		V[k] = L[i]; 
        i++; 
        k++;
	}
	
	while (j < n2) {
		V[k] = R[j]; 
        j++; 
        k++;
	}
}

void mergeSort_int(struct Pessoa *V, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		
		mergeSort_int(V, left, middle); 
        mergeSort_int(V, middle + 1, right); 
        merge_int(V, left, middle, right);
	}
} 


// Pelo nome
void merge_char (struct Pessoa *V, int left, int middle, int right) {
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	struct Pessoa L[n1], R[n2];
	
	for (i=0; i<n1; i++) {
		L[i] = V[left + i];
	}
	
	for (j=0; j<n2; j++) {
		R[j] = V[middle + j + 1];
	}
	
	i = 0;
	j = 0;
	k = left;
	
	while (i<n1 && j<n2) {
		if(L[i].Nome <= R[j].Nome) {
			V[k] = L[i];
			i++;
		}
		
		else {
			V[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	while (i < n1) {
		V[k] = L[i]; 
        i++; 
        k++;
	}
	
	while (j < n2) {
		V[k] = R[j]; 
        j++; 
        k++;
	}
}

void mergeSort_char(struct Pessoa *V, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		
		mergeSort_char(V, left, middle); 
        mergeSort_char(V, middle + 1, right); 
        merge_char(V, left, middle, right);
	}
}

// Pela nota
void merge_float (struct Pessoa *V, int left, int middle, int right) {
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	struct Pessoa L[n1], R[n2];
	
	for (i=0; i<n1; i++) {
		L[i] = V[left + i];
	}
	
	for (j=0; j<n2; j++) {
		R[j] = V[middle + j + 1];
	}
	
	i = 0;
	j = 0;
	k = left;
	
	while (i<n1 && j<n2) {
		if(L[i].Nota <= R[j].Nota) {
			V[k] = L[i];
			i++;
		}
		
		else {
			V[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	while (i < n1) {
		V[k] = L[i]; 
        i++; 
        k++;
	}
	
	while (j < n2) {
		V[k] = R[j]; 
        j++; 
        k++;
	}
}

void mergeSort_float(struct Pessoa *V, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		
		mergeSort_float(V, left, middle); 
        mergeSort_float(V, middle + 1, right); 
        merge_float(V, left, middle, right);
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n;
	cout << "\n Digite quantos cadastros deseja fazer \n ";
	cin >> n;
	
	Pessoa cadastro[n];
	vector <Pessoa> person;
	vector <Pessoa>::iterator it;
	
	for (int x=0; x<n; x++) {
		cout << "\n Cadastro n° " << x+1 << ":" << endl;
		cout << " Digite o nome: ";
		cin >> cadastro[x].Nome;
		
		cout << " Digite o número da matricula: ";
		cin >> cadastro[x].Matricula;
		
		cout << " Digite o valor da nota: ";
		cin >> cadastro[x].Nota;
		
		person.push_back(cadastro[x]);
		
		system("pause");
		system("cls");
	}
	
	cout << "O vetor estava assim:" << endl;
	for (it = person.begin(); it != person.end(); ++it) {
		cout << it->Nome << "\n" << it->Matricula << "\n" << it->Nota << endl;
		cout << "\n";
	}
	
	system("pause");
	system("cls");
	person.erase(person.begin(), person.end());
	
	int menu;
	cout << "Digite por qual campo deseja ordenar o vetor:" << endl;
	cout << "(1) Matrícula \n(2) Nome \n(3) Nota" << endl;
	cin >> menu;
	
	if (menu == 1) {
		mergeSort_int(cadastro, 0, n-1);	
	}
	
	else if (menu == 2) {
		mergeSort_char(cadastro, 0, n-1);
	}
	
	else if (menu == 3) {
		mergeSort_float(cadastro, 0, n-1);
	}
	
	else {
		cout << "Valor digitado inválido.\nDigite novamente";
		cin >> menu;
	}
	
	for (int x=0; x<n; x++) {
		person.push_back(cadastro[x]);
	}
	
	system("pause");
	system("cls");
	
	cout << "O vetor ordenado fica assim:" << endl;
	for (it = person.begin(); it != person.end(); ++it) {
		cout << it->Nome << "\n" << it->Matricula << "\n" << it->Nota << endl;
		cout << "\n";
	}
	
	return 0;
}

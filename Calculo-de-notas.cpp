#include <iostream>
#include <string>
using namespace std;

//headers
void menu();
void calcularMediaAluno();
void alunoEmRecuperacao();
void definirMedia();
void escalaDeNotas();
//-------------------------------

float notaMinima = 0;
float notaMaxima = 10;
float calculoMedia;
float media = 6;
float nota1 = -1;
float nota2 = -1;
string nomeAluno; 


int main(){
	menu();
	}

void menu() {

	int op = 0;
	while (op != 4) {
		system("cls");
		cout << "Calculo de Media Bimestral" << endl;
		cout << "1 - Calculo de Nota \n";
		cout << "2 - Calculo de Nota (incluindo P3) \n";
		cout << "3 - Definir a Media \n";
		cout << "4 - Definir escala de notas \n";
		cout << "5 - Sair \n\n";
		cout << "OBS: A Media foi pre-definida como " << media << ". \n";
		cout << "Por sua vez, a nota minima e maxima foram pre-definidas em uma escada de " << notaMinima << " a " << notaMaxima << ", respectivamente. \n";


		cout << "Opcao: " << endl;
		cin >> op; 
		if (op > 5) {
			cout << "Opcao inexistente." << endl;
		}
		 

		switch (op)
		{
			case 1: calcularMediaAluno();
				break;
			case 2: alunoEmRecuperacao();
				break;
			case 3: definirMedia();
				break;
			case 4: escalaDeNotas();
				break;
			case 5:
				return;
			default:
				break;
		}

	system("pause");

	}
	
}

void calcularMediaAluno()
{
	// Para verificar se há P3 com números binários.
	int verificarP3 = 1;

	cout << "Informe o nome do(a) aluno(a): \n";
	cin >> nomeAluno;

	while ((nota1 < notaMinima) || (nota1 > notaMaxima)) {
		cout << "Digite a primeira nota: \n";
		cin >> nota1;
		if ((nota1 < notaMinima) || (nota1 > notaMaxima)) {
			cout << "Digite uma nota dentro de uma escala de " << notaMinima << " a " << notaMaxima << ". \n";
		}
	}

	while ((nota2 < notaMinima) || nota2 > notaMaxima) {
		cout << "Digite a segunda nota: \n";
		cin >> nota2;
		if ((nota2 < notaMinima) || (nota2 > notaMaxima)) {
			cout << "Digite uma nota dentro de uma escala de " << notaMinima << " a " << notaMaxima << ". \n";
		} 
	}

	calculoMedia = (nota1 + nota2)/2;

	if (calculoMedia >= media) {
		cout << "O(a) aluno(a) " << nomeAluno << " foi aprovado com media " << calculoMedia << endl; 
	} else if (calculoMedia < media) {

		do {
			cout << "A media do(a) aluno(a)" << nomeAluno << " foi insuficiente. O(a) aluno(a) fez P3? \n Digite 1 para SIM ou 0 para NAO. \n";
			cin >> verificarP3;
			if ((verificarP3 < 0) || (verificarP3 > 1)) {
				cout << "Valor incompreendido. Digite novamente. \n\n";
			}
		} while ((verificarP3 < 0) || (verificarP3 > 1));

		if (verificarP3 == 0) {
			cout << "O(a) aluno(a) " << nomeAluno << " possui media " << calculoMedia << " ate a P3 (se fizer)" << endl;
		} else { 
			if ((calculoMedia < media) && (nota1 >= nota2)) {
			cout << "Digite a nota da P3: \n";
			cin >> nota2;
			cout << "Lembrete: a P3 substitui a menor nota do aluno. \n";
			calculoMedia = (nota1 + nota2)/2;
				if (calculoMedia >= media) {
					cout << "O(a) aluno(a) " << nomeAluno << " foi aprovado com media " << calculoMedia << endl;
				} else {
					cout << "O(a) aluno(a) " << nomeAluno << " foi reprovado com media " << calculoMedia << endl;
				}
			} else {
				cout << "Digite a nota da P3: ";
				cin >> nota1;
				cout << "Lembrete: a P3 substitui a menor nota do aluno. \n";
				calculoMedia = (nota1 + nota2)/2;
				if (calculoMedia >= media) {
					cout << "O(a) aluno(a) " << nomeAluno << " foi aprovado com media " << calculoMedia << endl;
				} else {
					cout << "O(a) aluno(a) " << nomeAluno << " foi reprovado com media " << calculoMedia << endl;
				}
			}
		}	
	}

	// Não há nota negativa, portanto as notas foram pré-definidas com -1, uma vez a escala precisa ser maior que zero.
	nota1 = -1;
	nota2 = -1;
}

void alunoEmRecuperacao() {

	cout << "Lembre-se: essa opcao inclui a P3 independentemente da primeira e segunda nota... \n";

	cout << "Digite o nome do(a) aluno(a): \n";
	cin >> nomeAluno;

	while ((nota1 < notaMinima) || nota1 > notaMaxima) {
		cout << "Digite a primeira nota: \n";
		cin >> nota1;
		if ((nota1 < notaMinima) || (nota1 > notaMaxima)) {
			cout << "Digite uma nota dentro de uma escala de " << notaMinima << " a " << notaMaxima << ". \n";
		} 
	}

	while ((nota2 < notaMinima) || nota2 > notaMaxima) {
		cout << "Digite a segunda nota: \n";
		cin >> nota2;
		if ((nota2 < notaMinima) || (nota2 > notaMaxima)) {
			cout << "Digite uma nota dentro de uma escala de " << notaMinima << " a " << notaMaxima << ". \n";
		} 
	}

	cout << "Lembrete: a P3 substitui a menor nota. \n";

	if (nota1 >= nota2) {

		do {
		cout << "Digite a nota da P3: \n";
		cin >> nota2;
			if ((nota2 < notaMinima) || (nota2 > notaMaxima)) {
				cout << "Digite uma nota dentro de uma escala de " << notaMinima << " a " << notaMaxima << ". \n";
			} 
		} while ((nota2 < notaMinima) || (nota2 > notaMaxima));


		calculoMedia = (nota1 + nota2)/2;


		if (calculoMedia >= media) {
			cout << "O(a) aluno(a) " << nomeAluno << " foi aprovado com media " << calculoMedia << endl;
		} else {
			cout << "O(a) aluno(a) " << nomeAluno << " foi reprovado com media " << calculoMedia << endl;
		}
		} else {
		
			do {
		cout << "Digite a nota da P3: \n";
		cin >> nota1;
			if ((nota1 < notaMinima) || (nota1 > notaMaxima)) {
				cout << "Digite uma nota dentro de uma escala de " << notaMinima << " a " << notaMaxima << ". \n";
			} 
		} while ((nota1 < notaMinima) || (nota1 > notaMaxima));

			calculoMedia = (nota1 + nota2)/2;

			if (calculoMedia >= media) {
				cout << "O(a) aluno(a) " << nomeAluno << " foi aprovado com media " << calculoMedia << endl;
			} else {
				cout << "O(a) aluno(a) " << nomeAluno << " foi reprovado com media " << calculoMedia << endl;
			}
		}
	
	// Não há nota negativa, portanto as notas foram pré-definidas com -1, uma vez a escala precisa ser maior que zero.
	nota1 = -1;
	nota2 = -1;
	
}

void definirMedia() {
	
	do {
		cout << "Determine a media minima: \n";
		cin >> media;
		if ((media < notaMinima) || (media > notaMaxima)) {
			cout << "Digite uma media dentro da escala estabelecida. \n";
		} 
	} while ((media < notaMinima) || (media > notaMaxima));

	cout << "Media atualizada com sucesso! \n";
}

void escalaDeNotas() {

	do {
		cout << "Determine a nota minima: \n";
		cin >> notaMinima;
		if (notaMinima < 0) {
			cout << "A nota minima precisa ser igual ou maior que zero. \n";
		} 
	} while (notaMinima < 0);

	cout << "Determine a nota maxima: \n";
	cin >> notaMaxima;

	cout << "Escala de notas atualizada com sucesso! \n";
	main();
}

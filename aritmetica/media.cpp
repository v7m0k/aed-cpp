/*Faça um programa que peça para ler 2 notas e 2 pesos (1 para cada nota) e depois mostre:
o  A média aritmética simples;
o  A média ponderada entre os dois valores (nota 1 com peso 1 e nota 2 com peso 2);
o  O valor necessário para recuperar a pior nota e passar com média igual ou superior a 6.0 considerando o uso da média aritmética simples (notas com pesos iguais);
o  O valor necessário para recuperar a pior nota e passar com média igual ou superior a 6.0, considerando o uso da média ponderada (nota 1 => peso 1, nota 2 => peso 2);
o  Qual das duas médias (aritmética, ponderada ou tanto faz) é mais benéfica para o aluno, ou seja, qual das duas médias deixa este aluno com a melhor nota.
Faça este programa de forma modular, ou seja, usando uma sub-rotina (função) para o cálculo de cada tarefa descrita acima.*/

#include <iostream>

using namespace std;

void media_arit (float n1, float n2, float p1, float p2) {
	float calc_arit, calc_pond;

	calc_arit = (n1 + n2)/2;

	cout << "A media aritmetica e " << calc_arit << endl;

	calc_pond = ((n1 * p1) + (n2 * p2))/(p1 + p2);

	cout << "A media ponderada e: " << calc_pond << endl;

	if (calc_arit < 6) {
		cout << "\nVoce esta reprovado!";
	} else {
		cout << "\nParabens, voce passou!";
	}

	if (calc_arit > calc_pond) {
		cout << "\nA melhor opcao e a media aritmetica, com nota: " << calc_arit << endl;
	}
	else {
		cout << "\nA melhor opcao e a media ponderada, com nota: " << calc_pond << endl;
	}
}

void resultado (float n1, float n2) {
	float media_total, total;

	media_total = (n1 + n2)/2;
	total = 12 - media_total;

	if (media_total >= 6) {
		cout << "\nTop!";
	}
	else {
		cout << "\nVoce precisa tirar: " << total << endl;
	}
}

int main(int argc, char** argv) {
	float n1, n2, p1, p2;

	cout << "Digite a primeira nota de 1 a 10: ";
	cin >> n1;
	cout << "Digite o peso: ";
	cin >> p1;

	cout << "Digite a segunda nota de 1 a 10: ";
	cin >> n2;
	cout << "Digite o peso: ";
	cin >> p2;

	media_arit(n1, n2, p1, p2);

	resultado(n1, n2);
	return 0;
}
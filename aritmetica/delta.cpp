/*Desenvolva os itens a seguir:
a)     Crie uma função que receba um valor e informe se ele é positivo ou não.
b)     Crie uma função que receba um valor e diga se é nulo ou não.
c)     Crie uma função que receba três valores, 'a', 'b' e 'c', que são os coeficientes de uma equação do segundo grau e retorne o valor do delta, que é dado por 'b² - 4ac'.
d)     Usando as 3 funções acima, crie um programa que calcula as raízes de uma equação do 2o grau:
ax² + bx + c = 0
Para ela existir, o coeficiente 'a' deve ser diferente de zero.
Se:
delta < 0: Não existem raízes reais;
delta = 0: existe uma única raiz
delta > 0: existem duas raízes reais*/

#include <iostream>

using namespace std;

void receba (float n1) {
	if (n1 > 0) {
		cout << "O valor: " << n1 << " e positivo." << endl;
	}
	else {
		cout << "O valor: " << n1 << " e negativo." << endl;	
	}
}

void nulo (float n1) {
	if (n1 == 0) {
		cout << "\nO valor e nulo.";
	}
	else {
		cout << "\nO valor nao e nulo." << endl;
	}
}

void valores (int a, int b, int c) {
	float b2, quatro, delta;
	
	b2 = b * b;
	quatro = 4 * a * c;
	delta = b2 - quatro;
	cout << "\nO delta e de: " << delta;
	
	if (delta < 0) {
		cout << "\nNao existem raizes reais";
	}
	else if (delta == 0) {
		cout << "\nExiste uma unica raiz";
	}
	else {
		cout << "\nExistem duas raizes reais";
	}
}

void resultado (int a, int b, int c) {
	
}

int main(int argc, char** argv) {
	float n1;
	int a, b, c;
	
	cout << "\nDigite um valor: ";
	cin >> n1;
	
	receba(n1);
	nulo(n1);
	
	cout << "\nDigite o valor de A: ";
	cin >> a;
	cout << "Digite o valor de B: ";
	cin >> b;
	cout << "Digite o valor de C: ";
	cin >> c;
	
	cout << "\nA equacao e: " << a << "x²" "+" << b << "x" "+" << c << "=0" << endl;
	
	valores(a, b, c);
	
	return 0;
}
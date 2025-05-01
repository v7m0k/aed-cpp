#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char** argv) {
    string frase;
    int letras, numeros=0, minusculas=0, pontuacao=0, i;

    cout << "\nDigite uma frase: ";
    getline(cin, frase);

    letras = frase.size();

    cout << "\nSua frase tem "<<letras<<" letras";

    for (i=0; i<letras; i++){
        if (isdigit(frase[i])) numeros++;
        if (islower(frase[i])) minusculas++;
        if (ispunct(frase[i])) pontuacao++;
    }

    cout << "\nSua frase tem " << numeros << " numeros";
    cout << "\nSua frase tem " << minusculas << " letras minusculas";
    cout << "\nSua frase tem " << pontuacao << " pontos";

    return 0;
}

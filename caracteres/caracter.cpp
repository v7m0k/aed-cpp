#include <iostream>
#include <string>

using namespace std;

int parametro(char c, string frase) {
    for(int i=0; i<frase.size(); i++){
        if(frase[i] == c) {
            return i;
        }
    }
}

int main (int argc, char** argv) {
    char c;
    string frase;

    cout << "\nDigite uma frase: ";
    getline(cin, frase);

    cout << "\nDigite o caractere que deseja encontrar: ";
    cin >> c;

    int x = parametro(c, frase);
    cout << "Foi encontrado na posicao: " << x << endl;

    return 0;
}
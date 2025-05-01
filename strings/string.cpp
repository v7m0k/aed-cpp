using namespace std;

void ler(string *frase) {
    cout << "\nDigite uma frase: ";
    getline(cin, *frase);
}

int contagem(string frase, char caracter) {
    int cont = 0;
    int qde;

    qde = frase.size();
    for(int i=0;i<qde; i++)
        if (frase[i] == caracter)
            cont++;
    return cont;
}

void vazio(string frase) {
    if(frase.empty()) {
        cout << "\nFrase vazia, escreva!";
    } else {
        cout << "\nBoa!";
    }
}

int main(int argc, char** argv) {
    string frase, cs;
    char c;

    ler(&frase);

    cout << "\nInforme o caracter: ";
    cin >> c;

    int x = contagem(frase, c);

    cout << "O caracter foi encontrado: " << x << " vezes.";

    vazio(frase);

    return 0;
}
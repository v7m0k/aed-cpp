#include <iostream>
using namespace std;

void ler_vetor(int *vet, int n) {
    system("cls");
    cout << "\nEntre com os elementos do vetor:\n";
    for (int k = 0; k < n; k++) {
        cout << "Elemento [" << k << "]: ";
        cin >> vet[k];
    }
}

void imprimir_vetor(int *vet, int n) {
    cout << "\nDados armazenados no vetor:\n";
    for (int j = 0; j < n; j++) {
        cout << "[" << vet[j] << "]" << endl;
    }
}

int negativado(int *vet, int n) {
    int count = 0;
    cout << "\nNumeros negativos no vetor:\n";
    for (int i = 0; i < n; i++) {
        if (vet[i] < 0) {
            cout << vet[i] << endl;
            count++;
        }
    }
    cout << "Total de negativos: " << count << endl;
    return count;
}

void imprimir_pares(int *vet, int n) {
    cout << "\nValores pares no vetor:\n";
    for (int i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) { //modulo
            cout << vet[i] << endl;
        }
    }
}

void maior_menor(int *vet, int n) {
    if (n == 0) {
        cout << "\nVetor vazio!" << endl;
        return;
    }

    int maior = vet[0], menor = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) maior = vet[i];
        if (vet[i] < menor) menor = vet[i];
    }

    cout << "\nMaior valor: " << maior << endl;
    cout << "Menor valor: " << menor << endl;
}

int main() {
    int vet[100];
    int op, qde = 0;

    do {
        cout << "\n\n===== MENU =====";
        cout << "\n1 - Ler vetor";
        cout << "\n2 - Imprimir o vetor";
        cout << "\n3 - Retornar os números negativos";
        cout << "\n4 - Imprimir os valores pares";
        cout << "\n5 - Imprimir os valores maiores e menores";
        cout << "\n0 - Encerrar o programa";
        cout << "\nEscolha uma opcao: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "\nQuantidade de elementos: ";
                cin >> qde;
                if (qde > 0 && qde <= 100) {
                    ler_vetor(vet, qde);
                } else {
                    cout << "Quantidade invalida. Tente novamente.\n";
                }
                break;

            case 2:
                imprimir_vetor(vet, qde);
                break;

            case 3:
                negativado(vet, qde);
                break;

            case 4:
                imprimir_pares(vet, qde);
                break;

            case 5:
                maior_menor(vet, qde);
                break;

            case 0:
                cout << "\nEncerrando o programa...\n";
                break;

            default:
                cout << "\nOpcao invalida. Tente novamente.\n";
                break;
        }
    } while (op != 0);

    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
    char str1[100];
    char str2[100];
    
    cout << "Digite a primeira string: ";
    cin.getline(str1, sizeof(str1));
    cout << "Digite a segunda string: ";
    cin.getline(str2, sizeof(str2));
    
    if (strcmp(str1, str2) == 0) {
        cout << "As strings sao iguais." << endl;
    }
    else {
        cout << "As strings nao sao iguais." << endl;
    }

    return 0;
}
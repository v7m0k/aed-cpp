#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, s1;
    int y = 0;

    cout << "\nDigite uma frase: ";
    getline(cin, s);

    int x = s.size();

    for (int i = x - 1; i >= 0; i--) {
        s1 += s[i];
    } //inverte a string

    cout << "\ns: " << s << endl;
    cout << "\ns1: " << s1 << endl;

    if (s == s1) {
        cout << "\nÉ palíndromo." << endl;
    } else {
        cout << "\nNão é palíndromo." << endl;
    }

    return 0;
}

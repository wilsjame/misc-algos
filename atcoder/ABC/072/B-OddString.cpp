#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    for (int i = 0; i < (int)S.length(); i += 2) {
        cout << S[i];
    }
    cout << endl;

    return 0;
}

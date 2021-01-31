#include <iostream>

using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    int k = 1;
    while (A >= 0 && B >= 0) {
        if (k % 2)
            A -= k;
        else
            B -= k;
        k++;
    }
    cout << (A < 0 ? "Vladik" : "Valera");

    return 0;
}

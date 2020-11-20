#include <iostream>
using namespace std;

int main() {
    char A, B;
    cin >> A >> B;

    if (A == B)
        cout << '=' << endl;
    else 
        cout << (A < B ? '<' : '>') << endl;

    return 0;
}

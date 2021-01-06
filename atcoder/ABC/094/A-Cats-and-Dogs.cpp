#include <iostream>
using namespace std;

int main() {
    int A, B, X;
    cin >> A >> B >> X;

    if (X >= A && X <= A + B) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}

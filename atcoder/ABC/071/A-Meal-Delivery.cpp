#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int X, A, B;
    cin >> X >> A >> B;

    cout << (abs(X - A) > abs(X - B) ? 'B' : 'A') << endl;

    return 0;
}

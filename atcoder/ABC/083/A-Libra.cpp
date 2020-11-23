#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, L, R;
    cin >> A >> B >> C >> D;

    L = A + B, R = C + D;

    if (L == R)
        cout << "Balanced" << endl;
    else 
        cout << (L > R ? "Left" : "Right") << endl;

    return 0;
}

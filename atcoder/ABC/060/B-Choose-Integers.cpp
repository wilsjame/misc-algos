#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    bool found = false;
    for (int k = 1; k <= B; k++)
        if ((A * k) % B == C)
            found = true;

    cout << (found ? "YES" : "NO") << endl;

    return 0;
}

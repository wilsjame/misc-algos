#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        // a ^ x = b
        // b ^ x = a
        int x;
        x = a ^ b;
        cout << x << endl;
    }
    return 0;
}

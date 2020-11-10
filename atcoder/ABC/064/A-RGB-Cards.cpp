#include <iostream>
using namespace std;

int main() {
    int R, G, B;
    cin >> R >> G >> B;
    int value = 100 * R + 10 * G + B;
    cout << (value % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}

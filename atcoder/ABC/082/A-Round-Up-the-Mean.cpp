#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int ave = ((A + B) + 2 - 1) / 2; // ceiling
    cout << ave << endl;

    return 0;
}

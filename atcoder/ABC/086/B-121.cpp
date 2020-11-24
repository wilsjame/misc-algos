#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    string A, B;
    cin >> A >> B;

    n = stoi(A + B);
    for (k = 1; k * k < n; k++) {}

    cout << (k * k == n ? "Yes" : "No") << endl;

    return 0;
}

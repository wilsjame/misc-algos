#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int d1, d2, d3;
    d1 = A + B;
    d2 = A + C;
    d3 = B + C;

    cout << min({d1, d2, d3});

    return 0;
}

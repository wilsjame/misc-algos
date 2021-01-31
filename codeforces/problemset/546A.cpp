#include <iostream>
using namespace std;
int main() {
    long b, d, n;
    cin >> b >> d >> n;
    long c = b * ( (n * (n + 1)) / 2 );
    if (c <= d) {
        cout << 0 << endl;
    }
    else {
        cout << c - d << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int x, cnt = 0;
    cin >> x;

    // count number of 1 bits
    while (x) {
        cnt += x&1;
        x >>= 1;
    }
    cout << cnt;

    return 0;
}

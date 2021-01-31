#include <iostream>
using namespace std;
int main() {
    int n, v, station = 1, pos = 1, c = 0;
    cin >> n >> v;

    if (v >= n - 1) {
        c = n -1;
    }
    else {
        c += pos * v;
        pos += v;
        while (pos++ < n) {
            c += ++station;
        }
    }
    cout << c << endl;

    return 0;
}

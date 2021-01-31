#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;

    int d = 1, cnt = v0;
    while (cnt < c) {
        v0 = min(v1, v0 + a);
        cnt += v0 - l;
        d++;
    }
    cout << d;

    return 0;
}

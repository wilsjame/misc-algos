#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll X, Y;
    cin >> X >> Y;

    ll a = Y, cnt = 0;
    while (a >= X) {
        cnt++;
        a /= 2;
    }

    cout << cnt << endl;

    return 0;
}

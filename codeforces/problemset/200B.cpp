#include <iostream>
using namespace std;

int main() {
    float n, d, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d;
        sum += d / 100;
    }
    cout << 100 * (sum / n) << endl;

    return 0;
}

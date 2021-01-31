#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int k = 1;
    if (N == 1) {
        cout << 1 << endl << 1 << endl;
    }
    else {
        for (;k * (k + 1) / 2 < N; k++) {}
        if (k * (k + 1) / 2 == N) {
            cout << k << endl;
        }
        else {
            cout << k - 1 << endl;
            k--;
        }
        int sum = 0;
        for (int i = 1; i < k; i++) {
            sum += i;
            cout << i << " ";
        }
        cout << N - sum << endl;
    }

    return 0;
}

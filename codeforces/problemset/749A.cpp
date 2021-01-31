#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cout << N / 2 << endl;
    if (N % 2 == 0) {
        for (int i = 0; i < N / 2; i++)
            cout << 2 << " ";
    }
    else {
        for (int i = 0; i + 1 < N / 2; i++)
            cout << 2 << " ";
        cout << 3;
    }

    return 0;
}

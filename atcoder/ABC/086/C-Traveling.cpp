#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N, T, X, Y;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> T >> X >> Y;
        A[i][0] = T;
        A[i][1] = X;
        A[i][2] = Y;
    }

    bool found = true;
    int x = 0, y = 0, dt = 0, d;
    for (int i = 0; i < N && found; i++) {
        T = A[i][0];
        X = A[i][1];
        Y = A[i][2];
        dt = T - dt;
        d = abs(X- x) + abs(Y - y);

        if (d <= dt && d % 2 == dt % 2) {
             x = X;
             y = Y;
             dt = T;
        }
        else {
            found = false;
            break;
        }

    }

    cout << (found ? "Yes" : "No") << endl;

    return 0;
}

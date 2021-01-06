#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, X, L = 0, R = 0;
    cin >> N >> M >> X;
    for (int i, k = 0; k < M; k++) {
        cin >> i;
        L += i < X;
        R += i > X;
    }
    cout << min(L, R) << endl;
    
    return 0;
}

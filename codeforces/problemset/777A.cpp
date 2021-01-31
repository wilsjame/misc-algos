#include <iostream>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    N %= 6;
    for (int i = N; i > 0; i--) {
        if (i % 2) {
            if (X == 0 || X == 1) 
                X == 0 ? X = 1 : X = 0;
        }
        else {
            if (X == 1 || X == 2)
                X == 2 ? X = 1 : X = 2;
        }
    }
    cout << X;

    return 0;
}

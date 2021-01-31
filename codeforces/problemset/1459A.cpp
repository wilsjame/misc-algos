#include <iostream>
#include <vector>
using namespace std;

#define print(x) cerr << #x << " is " << x << endl;

int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> R(N), B(N);
        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            R[i] = c - '0';
        }
        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            B[i] = c - '0';
        }

        int r = 0, b = 0;
        for (int i = 0; i < N; i++) {
            if (R[i] > B[i]) {
                r++;
            }
            else if (B[i] > R[i]) {
                b++;
            }
        }
        if (r > b) {
            cout << "RED\n";
        }
        else if (b > r) {
            cout << "BLUE\n";
        }
        else {
            cout << "EQUAL\n";
        }
    }

    return 0;
}

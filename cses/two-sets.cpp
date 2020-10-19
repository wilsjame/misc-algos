#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll N;
    cin >> N;

    ll S = N*(N + 1) / 2;
    if (S % 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        if (N % 2 == 0) {
            // S is even and N is even
            // meet in the middle
            cout << N / 2 << endl;
            for (int i = 0; i < N /2; i += 2) 
                cout << 1 + i << " " << N - i << " ";
            cout << endl << N / 2 << endl;
            for (int i = 1; i < N /2; i += 2) 
                cout << 1 + i << " " << N - i << " ";
        }
        else {
            // S is even and N is odd
            // N = {3, 7, 11, 15, ...}, 4k + 3
            // since each gap is 4 and even
            // treat them as meet in the middles
            if (N == 3) {
                cout << "2\n1 2\n1\n3\n";
            }
            else {
                cout << (N + 1) / 2 << endl << "1 2 ";
                for (int i = 3; i + 4 <= N; i += 4) 
                    cout << i + 1 << " " << i + 4 << " ";
                cout << endl << N / 2 << endl << "3 ";
                for (int i = 3; i + 4 <= N; i += 4) 
                    cout << i + 2 << " " << i + 3 << " ";
            }
        }
    }

    return 0;
}

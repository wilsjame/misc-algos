#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto &a : A)
        cin >> a;

    int d_two = 0, d_four = 0, odd = 0;
    for (auto k : A) {
        if (k % 4 == 0) {
            d_four++;
        }
        else if (k % 2 == 0) {
            d_two++;
        }
        else {
            odd++;
        }
    }

    if (d_two == 0) {
        cout << (d_four >= odd - 1 ? "Yes" : "No") << endl;
    }
    else {
        cout << (d_four >= odd ? "Yes" : "No") << endl;
    }

    return 0;
}


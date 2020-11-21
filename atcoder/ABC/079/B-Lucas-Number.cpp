#include <iostream>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;

    ll L[86 + 1];
    L[0] = 2, L[1] = 1;

    for (int i = 2; i <= 86; i++)
        L[i] = L[i - 2] + L[i - 1];

    cout << L[N] << endl;

    return 0;
}

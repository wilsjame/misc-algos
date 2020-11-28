#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    ll march[5] = {0};
    for (int i = 0; i < N; i++) {
        string n;
        cin >> n;
        if (n[0] == 'M') march[0]++;
        if (n[0] == 'A') march[1]++;
        if (n[0] == 'R') march[2]++;
        if (n[0] == 'C') march[3]++;
        if (n[0] == 'H') march[4]++;
    }

    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += march[i] * march[j] * march[k];
            }
        }
    }
    cout << ans << endl;

    return 0;
}

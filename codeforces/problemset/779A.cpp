#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int cnt[6] = {}; // [1-5]
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &x : A) 
        cin >> x, cnt[x]++;
    for (auto &x : B) 
        cin >> x, cnt[x]--;

    int s = 0;
    for (int x = 1; x <= 5; x++) {
        s += abs(cnt[x]);
        if (cnt[x] % 2) {
            cout << -1;
            return 0;
        }
    }
    cout << s / 4;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    long long sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum += x;
    }
    sort(a.begin(), a.end());
    long long res = sum;
    for (int i = 0; i < n - 1; i++) {
        res += sum;
        sum -= a[i];
    }
    cout << res << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    int res = 0;
    int price = INT_MAX;
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        a[i] = p;

        price = min(price, a[i].second);
        res += price * a[i].first;
    }
    cout << res << endl;

    return 0;
}

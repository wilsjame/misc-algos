// sort, iterate, binary search,
// O(nlogn + q + logn)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (auto &x: prices)
        cin >> x;
    sort(prices.begin(), prices.end());

    int q, c;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> c;
        auto up = upper_bound (prices.begin(), prices.end(), c);
        cout << up - prices.begin() << endl;
    }

    return 0;
}

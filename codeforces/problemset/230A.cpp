#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> d(n);
    for (int x, y, i = 0; i < n; i++) {
        cin >> x >> y;
        d[i] = {x, y};
    }
    // greedy: kill dragon with lowest strength first
    sort(d.begin(), d.end());
    bool win = true;
    for (int i = 0; i < n; i++) {
        if (d[i].first < s) {
            s += d[i].second;
        }
        else {
            win = false;
            break;
        }
    }
    win ? cout << "YES" : cout << "NO";

    return 0;
}

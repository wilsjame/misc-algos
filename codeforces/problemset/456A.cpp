#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        a.push_back(make_pair(p, c));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < n; i++) {
        if (a[i].second > a[i + 1].second) {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;
    return 0;
}

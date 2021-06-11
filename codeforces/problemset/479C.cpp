#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());
    int day = -1;

    for (int i = 0; i < n; i++) {
        int a, b;
        a = v[i].first;
        b = v[i].second;
        if (day <= b) {
            day = b;
        }
        else {
            day = a;
        }
    }
    cout << day << endl;

    return 0;
}

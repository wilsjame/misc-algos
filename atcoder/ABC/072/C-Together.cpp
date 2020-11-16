#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &k : A) 
        cin >> k;

    int ans = 0;
    unordered_map<int, int> count;

    for (int x : A) {
        count[x - 1]++;
        count[x]++;
        count[x + 1]++;
        ans = max({ans, count[x - 1], count[x], count[x + 1]});
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    map<int, int> mymap;
    vector<int> count;
    for (int i = 0; i < N; i++) {
        int z;
        cin >> z;
        mymap[z]++;
    }
    for (auto p : mymap) {
        count.push_back(p.second);
    }
    sort(count.begin(), count.end());

    int res = 0;
    if ((int)count.size() > K) {
        int r = count.size() - K;
        for (int i = 0; i < r; i++)
                res += count[i];
    }

    cout << res << endl;

    return 0;
}

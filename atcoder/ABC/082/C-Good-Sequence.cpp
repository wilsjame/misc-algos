#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;
    unordered_map<int, int> count;
    for (int i = 0; i < N; i++) {
        int z;
        cin >> z;
        count[z]++;
    }

    for (auto p : count) {
        int num = p.first, cnt = p.second;
        if (cnt > num)
            ans += cnt - num;
        else if (cnt < num)
            ans += cnt;
    }

    cout << ans << endl;

    return 0;
}

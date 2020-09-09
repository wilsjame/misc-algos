#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, sum, m = 1e9 + 7, count[1000000 + 5] = {0};
    cin >> n >> sum;
    vector<int> coins(n);
    for (auto &c : coins) 
        cin >> c;

    count[0] = 1;
    for (auto c : coins) {
        for (int x = 1; x <= sum; x++) {
            if (x - c >= 0) {
                count[x] += count[x - c];
                count[x] %= m;
            }
        }
    }
    cout << count[sum];

    return 0;
}


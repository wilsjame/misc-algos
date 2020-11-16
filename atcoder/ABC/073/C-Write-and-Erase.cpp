#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> count;
    int N, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (++count[x] % 2)
            ans++;
        else
            ans--;
    }

    cout << ans << endl;

    return 0;
}

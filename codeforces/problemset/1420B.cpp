#include <iostream> 
#include <vector>
using namespace std;

// return the position of the leftmost 1 bit
int leftmost(int x) {
     return __builtin_clz(x);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &k : a) cin >> k;

        // two pass O(n)
        // only care about highest order bit 
        long long cnt = 0;
        vector<int> msb(32+1,0);
        for (int i = 0; i < n; i++) {
            msb[leftmost(a[i])]++;
        }
        // sum pairs
        for (long long n : msb) {
            cnt += (n * (n - 1)) / 2;
        } 
        cout << cnt << endl;
    }

    return 0;
}

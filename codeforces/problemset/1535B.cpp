#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b , a % b);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int e = 0;
        vector<int> o;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            if (k % 2) {
                o.push_back(k);
            }
            else {
                e++;
            }
        }
        int ans = 0;
        // evens
        for (int i = 1; i <= e; i++) {
            ans += n - i;
        }
        // odds
        for (int i = 0; i + 1 < (int)o.size(); i++) {
            for (int j = i + 1; j < (int)o.size(); j++) {
                int a = o[i];
                int b = o[j];
                if (gcd(a, b) > 1) {
                    ans++; 
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

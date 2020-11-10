#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, sum = 0;;
    cin >> N;
    vector<int> A(N);
    for (auto &k : A) { 
        cin >> k;
        sum += k;
    }

    // yeah this is kinda messy
    int ans = sum;
    sort(A.begin(), A.end());
    for (int i = 0; i < N && ans % 10 == 0; i++) {
        if (A[i] % 10 != 0) {
            ans -= A[i];                                        
        }
    }
    if (ans == sum && ans % 10 == 0) 
        cout << 0 << endl;
    else 
        cout << ans << endl;

    return 0;
}

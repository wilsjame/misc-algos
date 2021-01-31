#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (auto& a : A) 
            cin >> a;
        int first = -1, last = -1; 
        for (int i = 0; i < N && first == -1; i++) {
            if (A[i] == 1)
                first = i;
        }
        for (int i = N - 1; i >= 0 && last == -1; i--) {
            if (A[i] == 1)
                last = i;
        }
        int ans = 0;
        for (int i = first; i < last; i++) {
            if (A[i] == 0)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int ans = 0;
    vector<int> A(3);
    for (int i = 0; i < 3; i++) 
        cin >> A[i];
    for (; (A[0] != A[1]) || (A[0] != A[2]); ans++) {
        sort(A.begin(), A.end());
        if (A[2] - A[0] > 1) {
            A[0] += 2;
        }
        else {
            A[0]++;
            A[1]++;
        }
    }
    cout << ans << endl;
    return 0;
}



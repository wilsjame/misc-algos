#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int res = 1;
    for (int i = 0; i < N; i++) {
        res = min(res * 2, res + K);
    }
    cout << res << endl;
    
    return 0;
}

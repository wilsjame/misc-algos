#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    if (2 * K >= B - A + 1) {
        for (int i = A; i <= B; i++)
            cout << i << endl;
    }
    else {
        vector<int> a(K), b(K);
        for (int i = 0; i < K; i++) 
            a[i] = A + i; 
        for (int i = 0; i < K; i++) 
            b[i] = B - i; 
        reverse(b.begin(), b.end());
        for (auto x : a) 
            cout << x << endl;
        for (auto x : b)
            cout << x << endl;
    }
    return 0;
}

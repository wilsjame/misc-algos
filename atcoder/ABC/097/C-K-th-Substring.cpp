#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define print(x) cerr << #x << " is " << x << endl;

int main() {
    string S;
    int K;
    cin >> S >> K;

    // K lexicographically smallest substring
    // will be at most length K. 
    // Generate all substrings of K length or
    // less, sort, amd find Kth smallest.
    set<string> myset ;
    int N = S.length();
    for (int i = 0; i < N; i++) {
        string sub;
        for (int j = i; j < min(N, i + K); j++) {
            sub += S[j];
            myset.insert(sub);
        }
    }
    vector<string> v(myset.begin(), myset.end());
    sort(v.begin(), v.end());
    cout << v[K - 1] << endl;

    return 0;
}

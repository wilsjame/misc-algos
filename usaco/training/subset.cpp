/*
ID: jgwilso1
PROG: subset
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int mxN = 39;
long long ways[mxN+1][(mxN*(mxN+1))/2+1];

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int n;
    cin >> n;
    int mxsum = (n*(n+1))/2;
    if (mxsum % 2) {
        cout << 0 << endl;
        return 0;
    }
    // ways[i][j] ways to make sum j with i elements
    ways[1][0] = 1;
    ways[1][1] = 1;
    for (int element = 2; element <= n; element++) {
        int p = 0; // placeholder shouldn't really need this...
        // copy previous row
        for (int sum = 0; sum <= mxsum; sum++) {
            ways[element][sum] = ways[element-1][sum];
            if (ways[element][sum]) p++;
        }
        // introduce new element
        for (int sum = 0; sum < p; sum++) { 
            ways[element][sum+element] += ways[element-1][sum]; 
        }
    }
    cout << ways[n][mxsum/2]/2 << endl;

    return 0;
}

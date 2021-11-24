/*
ID: jgwilso1
PROG: sprime
LANG: C++                 
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int mxN = 8;
int n;

bool isprime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int x = 2; x*x <= n; x++) {
        if (n%x == 0) return false;
    }
    return true;
}

void dfs(int sz, int x) {
    if (sz == n) {
        cout << x << endl;
        return;
    }
    else {
        for (int i = 1; i <= 9; i++) {
            int temp = x*10;
            temp += i;
            if (isprime(temp)) {
                dfs(sz+1, temp);
            }
        }
    }

}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> n;
    dfs(0, 0);
    return 0;
}

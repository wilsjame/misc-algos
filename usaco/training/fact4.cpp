/*
ID: jgwilso1
PROG: fact4
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    int n;
    cin >> n;
    // - multiplying by 10 appends zero,
    // remove all pairs of 2 and 5 degrees
    // - number of 2 degrees > number of 5 degrees
    int last = 1;
    int deg2 = 0;
    for (int i = n; i >= 1; --i) {
      int num = i;
      while (num % 2 == 0) {
        num /= 2;
        deg2++;
      }
      while (num % 5 == 0) {
        num /= 5;
        deg2--;
      }
      last = (last * num) % 10;
    }
    for (int i = 0; i < deg2; i++) {
      last = (last * 2) % 10;
    }
    cout << last << endl;

    return 0;
}

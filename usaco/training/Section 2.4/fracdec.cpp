/*
ID: jgwilso1
PROG: fracdec
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    int n, d, rem;
    cin >> n >> d;

    string q = to_string(n / d) + ".";
    if (n % d == 0) {
      q += "0";
    }
    else { // long division
      int remPos[2000000];
      n %= d;
      n *= 10;
      while (1) {
        if (n == 0 || remPos[n]) 
          break;
        remPos[n] = q.length();
        q += to_string(n / d);
        n %= d;
        n *= 10;
      }
      if (n != 0) {
        q.insert(remPos[n], "(");
        q += ")";
      }
    }
    for (int i = 1; i <= q.length(); i++) {
      cout << q[i - 1];
      if (i % 76 == 0) 
        cout << endl;
    }
    cout << endl;

    return 0;
}

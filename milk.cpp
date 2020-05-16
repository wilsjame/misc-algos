/*
ID: jgwilso1
PROG: milk
LANG: C++                 
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    int milkreq, numfarmers, q, c, result = 0;
    map<int,int> ht;

    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    cin >> milkreq;
    cin >> numfarmers;

    for (int i = 0; i < numfarmers; i++) {
        cin >> c >> q;
        ht[c] += q;
    }
    for (auto x: ht) { 
        if (milkreq == 0) { break; }
        c = x.first;
        q = x.second;
        while (milkreq > 0 && q > 0) {
            result += c;
            q--;
            milkreq--;
        }
    }
    cout << result << endl;

    return 0;
}

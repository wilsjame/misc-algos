#include <iostream>
#include <string>
#include <set>
using namespace std;
/*
bool distinct(int x) {
    bool res;
    set<char> set;
    string s = to_string(x);
    for (auto d : s) {
        set.insert(d);
    }
    set.size() == s.size() ? res = true : res = false;
    return res;
}
*/
int main() {
    int y, a, b, c, d;
    cin >> y;
    //while (!distinct(++y)) {}
    do {
        y++,
        a = y/1000;
        b = y/100%10;
        c = y/10%10;
        d = y%10;
    }
    while (a == b || a == c || a == d || b == c || b == d || c == d);
    cout << y << endl;
    return 0;
}

#include <iostream>
#include <set>
using namespace std;
int main() {
    set<char> s;
    char c;
    while (cin >> c) {
        s.insert(c);
    }
    cout << (s.size() % 2 == 0 ? "CHAT WITH HER!\n" : "IGNORE HIM!\n");
    return 0;
}

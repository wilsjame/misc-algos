#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    cout << ((s.find("0000000") != string::npos || s.find("1111111") != string::npos) ? "YES" : "NO") << endl;
    return 0;
}

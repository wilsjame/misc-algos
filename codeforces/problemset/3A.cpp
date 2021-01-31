#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string s, f;
    cin >> s >> f;

    vector<string> a;
    while (s != f) {
        char x, y;
        x = s[0]; y = s[1];

        if (x > f[0] && y == f[1]) {
            a.push_back("L");
            s[0]--;
        }
        else if (x < f[0] && y == f[1]) {
            a.push_back("R");
            s[0]++;
        }
        else if (x == f[0] && y < f[1]) {
            a.push_back("U");
            s[1]++;
        }
        else if (x == f[0] && y > f[1]) {
            a.push_back("D");
            s[1]--;
        }
        else if (x > f[0] && y < f[1]) {
            a.push_back("LU");
            s[0]--; s[1]++;
        }
        else if (x > f[0] && y > f[1]) {
            a.push_back("LD");
            s[0]--; s[1]--;
        }
        else if (x < f[0] && y < f[1]) {
            a.push_back("RU");
            s[0]++; s[1]++;
        }
        else if (x < f[0] && y > f[1]) {
            a.push_back("RD");
            s[0]++; s[1]--;
        }
        else {
            cerr << "error" << endl; break;
        }
        //cerr << "s[0] " << s[0] << " s[1] " << s[1] << endl;
        //cerr << "f[0] " << f[0] << " f[1] " << f[1] << endl;
    }

    cout << a.size() << endl;
    for (auto x : a ) {
        cout << x << endl;
    }
    
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++) {
        s1[i] = toupper(s1[i]); 
        s2[i] = toupper(s2[i]);
    }
    cerr << "trace";
    cerr << s1 << s2 << endl;

    if (s1 == s2) {
        cout << 0 << endl;
    }
    else {
        for (int i = 0; i < s1.size(); i++) {
            if (toupper(s1[i]) != toupper(s2[i])) {
                if (toupper(s1[i]) < toupper(s2[i])) {
                    cout << -1 << endl;
                    break;
                }
                else {
                    cout << 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;

        if(s.size() <= 10) {
            cout << s << endl;
        }
        // too long
        else {
            string abbr;
            abbr = s[0] + to_string(s.size() - 2) + s[s.size() - 1];
            cout << abbr << endl;
        }

    }

    return 0;
}


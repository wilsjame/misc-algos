#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    // positions
    int h = -1, e = -1, l1 = -1, l2 = -1, o = -1;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == 'h' && h < 0) 
            h = i;
        else if (ch == 'e' && e < 0 && h >= 0)
            e = i;
        else if (ch == 'l' && l1 < 0 && e > 0)
            l1 = i;
        else if (ch == 'l' && l2 < 0 && l1 > 0)
            l2 = i;
        else if (ch == 'o' && o < 0 && l2 > 0)
            o = i;
    }
    if (h >= 0 && e > 0 && l1 > 0 && l2 > 0 && o > 0) 
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

#include <iostream>
using namespace std;
int main() {
    string s = "";
    char c;
    int upper = 0, lower = 0;
    while(cin >> c) {
        c <= 90 ? upper++ : lower++;
        s += c;
    }
    cerr << "upper: " << upper << " lower: " << lower << endl;
    cerr << "size " << s.size() << endl;
    if (upper == lower) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= 90) 
                s[i] += 32; 
        }
    }
    else if (lower > upper) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= 90)
                s[i] += 32;
        }
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > 90)
                s[i] -= 32;
        }
    }
    cout << s << endl;
    
    return 0;
}

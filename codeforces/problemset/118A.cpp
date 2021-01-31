#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U' ||
            c == 'y' || c == 'Y') 
        return true;
    else 
        return false;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
            s.erase(s.begin() + i--);
        }
        else {
            // it's a consonant
            // insert '.' before it
            s.insert(s.begin() + i++, '.');
            if (s[i] <= 'Z') {
                // make it uppercase
                s[i] += 32;
            }
        }
    }
    cout << s;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    char ans = 'Z';
    int count[26] = {};
    for (char C : S) 
        count[C - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (count[i] == 0) {
            ans = i + 'a';
            break;
        }
    }

    if (ans == 'Z')
        cout << "None" << endl;
    else 
        cout << ans << endl;

    return 0;
}

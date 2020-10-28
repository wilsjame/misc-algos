#include <iostream>
using namespace std;

int main() {
    char m[256] = {};
    char C; 
    cin >> C;
    m[(int)'a'] = m[(int)'e'] = m[(int)'i'] = m[(int)'o'] = m[(int)'u'] = 1;
    if (m[(int)C]) 
        cout << "vowel";
    else
        cout << "consonant";

    return 0;
}


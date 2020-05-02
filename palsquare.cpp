/*
ID: jgwilso1
PROG: palsquare
LANG: C++                 
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// returns '0'-'9' for 0-9 and 'A' for 10, 'B' for 11, and so on
char convert(int n) {
    if (n >= 0 && n <= 9) {
        return char(n +'0');
    }
    // we want 10 to output A, 11 B, ...
    // char(65) = A, char(66) = B, ...
    // char(10+55) = A, char(11+55) = B, ...
    return char(n + 55);
}

// converts a number base 10 to a number base B
string convert_to_base(int n, int B) {
    string result;
    stack<char> st;
    while(n > 0) {
        st.push(convert(n % B));
        n = n / B;
    }
    while (!st.empty()) {
        result += st.top(); st.pop();
    }
    return result;
}

bool is_palindrome(string s) {
    stack<char> st;
    int index;
    for (index = 0; index < s.size() / 2; index++) {
        st.push(s[index]);
    }
    if (s.size() % 2 != 0) {
        index++; // ignore middle char in odd length words
    }
    while (!st.empty()) {
        if (st.top() != s[index++]) {
            return false;
        }
        st.pop();
    }
    return true;
}

int main() {
    cerr << "%%%%%_program start_%%%%%\n";
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int B;
    cin >> B;
    for (int n = 1; n <= 300; n++) {
        string sq = convert_to_base(n * n, B);
        if (is_palindrome(sq)) {
            cout << convert_to_base(n, B) << " " << sq << endl;
        }
    }
    return 0;
}

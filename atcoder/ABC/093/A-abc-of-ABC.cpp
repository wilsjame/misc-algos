#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    if ((S.find('a') != string::npos && S.find('b') != string::npos) && S.find('c') != string::npos) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;

    cout << count(S.begin(), S.end(), '1') << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    cout << S[0] << S.length() - 2 << S[S.length() - 1] << endl;

    return 0;
}

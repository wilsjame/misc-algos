#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    string ans = "EQUAL";
    if (A.length() > B.length()) {
        ans = "GREATER";
    }
    else if (A.length() < B.length()) {
        ans = "LESS";
    }
    else {
        for (int i = 0; i < (int)A.length() && ans == "EQUAL"; i++) {
            if (A[i] > B[i])
                ans = "GREATER";
            else if (A[i] < B[i])
                ans = "LESS";
        }
    }
    cout << ans << endl;

    return 0;
}

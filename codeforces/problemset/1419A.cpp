#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        deque<int> raze(0), breach(0);
        for (int i = 0; i < n; i++) {
            int num = s[i] - '0';
            // raze's turn 1, 3, 5...
            if ((i + 1) % 2) {
                if (num % 2) 
                    raze.push_front(num);
                else
                    raze.push_back(num);
            }
            // breach's turn
            else {
                if (num % 2 == 0)
                    breach.push_front(num);
                else
                    breach.push_back(num);
            }
        }
        // last pick goes to raze
        if (n % 2) {
            if (raze.front() % 2)
                cout << 1;
            else
                cout << 2;
        }
        // last pick goes to breach
        else {
            if (breach.front() % 2 == 0)
                cout << 2;
            else 
                cout << 1;
        }
        cout << endl;
    }

    return 0;
}

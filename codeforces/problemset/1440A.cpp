#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        int N, C0, C1, H;
        cin >> N >> C0 >> C1 >> H >> S;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            char k =  S[i];
            if (C0 + H < C1 && k == '1') {
                ans += C0 + H;
            }
            else if (C1 + H < C0 && k == '0') {
                ans += C1 + H;
            }
            else if (k == '1') {
                ans += C1;
            }
            else {
                ans += C0;
            }
        }

        cout << ans << endl;
    }
	return 0;
}

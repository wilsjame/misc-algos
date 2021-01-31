#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<char>> A(N, vector<char> (N));
        for (auto& row : A)
            for (auto& a : row)
                cin >> a;

        char SR, SB, FT, FL;
        SR = A[0][1];
        SB = A[1][0];
        FT = A[N - 2][N - 1];
        FL = A[N - 1][N - 2];

        if ((SR == SB) && (FT == FL) && (SR != FT)) {
            cout << "0\n";
        }
        else if ((SR == SB) && (FT == FL) && (SR == FT)) {
            cout << "2\n1 2\n2 1\n";
        }
        else if ((SR == SB) && (FT != FL)) {
            cout << "1\n";
            if (FT == SR) 
                cout << N - 1 << " " << N << endl;
            else
                cout << N << " " << N - 1 << endl;
        }
        else if ((FT == FL) && (SR != SB)) {
            cout << "1\n";
            if (SR == FT) 
                cout << "1 2\n";
            else
                cout << "2 1\n";
        }
        else if ((SR != SB) && (FT != FL)) {
            cout << "2\n";
            SR = SB;
            cout << "1 2\n";
            if (FT == SR) 
                cout << N - 1 << " " << N << endl;
            else
                cout << N << " " << N - 1 << endl;
        }
    }

    return 0;
}

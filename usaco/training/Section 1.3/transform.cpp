/*
ID: jgwilso1
PROG: transform
LANG: C++                 
*/
// TODO tidy :D feels bulky :/
// consider a board data structure
// that can be passed and returned
// around instead of hardcoding
// transforms in the square class

#include <iostream>
#include <vector>

using namespace std;

class Square {
    int N;
    vector<vector<char>> grid;
    vector<vector<char>> grid_90;
    vector<vector<char>> grid_180;
    vector<vector<char>> grid_270;
public:
    Square(int x) { N = x; }

    void addRow(vector<char> r) { grid.push_back(r); }

    void calcRotations() {
        //assert(!grid.empty());
        grid_90 = grid;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                grid_90[j][(N-1)-i] = grid[i][j];
            }
        }
        grid_180 = grid_90;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                grid_180[j][(N-1)-i] = grid_90[i][j];
            }
        }
        grid_270 = grid_180;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                grid_270[j][(N-1)-i] = grid_180[i][j];
            }
        }
    }

    void calcReflections() {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N/2; j++) {
                swap(grid[i][j], grid[i][N-1-j]);
            }
            for (int j=0; j<N/2; j++) {
                swap(grid_90[i][j], grid_90[i][N-1-j]);
            }
            for (int j=0; j<N/2; j++) {
                swap(grid_180[i][j], grid_180[i][N-1-j]);
            }
            for (int j=0; j<N/2; j++) {
                swap(grid_270[i][j], grid_270[i][N-1-j]);
            }
        }
    }

    vector<vector<char>> getGrid(int deg) { 
        vector<vector<char>> r;
        switch (deg) {
            case 0 : r = grid;
                     break;
            case 90 : r = grid_90;
                      break;
            case 180 : r = grid_180;
                       break;
            case 270 : r = grid_270;
                       break;
        }
        return r;
    }

    // debugging
    void print(vector<vector<char>> g) {
        for (auto const& m : g) {
            for (auto const& n : m) {
                cout << n;
            }
            cout << '\n';
        }
    }
};

int main() {
    freopen ("transform.in","r",stdin);
    freopen ("transform.out","w",stdout);

    int N;
    cin >> N;
    Square square(N);
    Square squareb(N);
    char c;
    vector<char> row;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> c;
            row.push_back(c);
        }
        square.addRow(row);
        row.clear();
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> c;
            row.push_back(c);
        }
        squareb.addRow(row);
        row.clear();
    }

    bool no_change = (square.getGrid(0) == squareb.getGrid(0)) ? true : false;

    square.calcRotations();

    if (square.getGrid(90) == squareb.getGrid(0)) {
        cout << "1" << endl;
        return 0;
    }
    else if (square.getGrid(180) == squareb.getGrid(0)) {
        cout << "2" << endl;
        return 0;
    }
    else if (square.getGrid(270) == squareb.getGrid(0)) {
        cout << "3" << endl;
        return 0;
    }
    
    square.calcReflections();

    if (square.getGrid(0) == squareb.getGrid(0)) {
        cout << "4" << endl;
    }
    else if (square.getGrid(90) == squareb.getGrid(0)) {
        cout << "5" << endl;
    }
    else if (square.getGrid(180) == squareb.getGrid(0)) {
        cout << "5" << endl;
    }
    else if (square.getGrid(270) == squareb.getGrid(0)) {
        cout << "5" << endl;
    }
    else if (no_change) {
        cout << "6" << endl;
    }
    else {
        cout << "7" << endl;
    }

    return 0;
}

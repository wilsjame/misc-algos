/*
ID: jgwilso1
PROG: ratios
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> p;
int goal[3];
int mix[3][3];
int ans[4];
bool stop;

void search() {
  if ((int)p.size() == 3) {
    // mix this ratio permutation
    int curmix[3][3];
    for (int i = 0; i < 3; i++) { 
      for (int j = 0; j < 3; j++) {
        curmix[i][j] = mix[i][j];
        curmix[i][j] *= p[i];
      }
    }
    int x = curmix[0][0] + curmix[1][0] + curmix[2][0];
    int y = curmix[0][1] + curmix[1][1] + curmix[2][1];
    int z = curmix[0][2] + curmix[1][2] + curmix[2][2];
    // integers only
    if ((goal[0] == 0 && x == 0) || (goal[0] > 0 && (x % goal[0] == 0))) {
    if ((goal[1] == 0 && y == 0) || (goal[1] > 0 && (y % goal[1] == 0))) {
    if ((goal[2] == 0 && z == 0) || (goal[2] > 0 && (z % goal[2] == 0))) {
      // one or more goals might be zero -_- 2^3 permutations casework.. def a better way to do this xD
      bool found = false;
      if (goal[0] == 0 && goal[1] == 0 && goal[2] == 0) {
        found = true;
      }
      else if (goal[0] == 0 && goal[1] == 0) {
        if (x == 0 && y == 0 && z > 0) {
          found = true;
        }
      }
      else if (goal[0] == 0 && goal[2] == 0) {
        if (x == 0 && z == 0 && y > 0) {
          found = true;
        }
      }
      else if (goal[1] == 0 && goal[2] == 0) {
        if (y == 0 && z == 0 && x > 0) {
          found = true;
        }
      }
      else if (goal[0] == 0) {
        if (x == 0 && y > 0 && z > 0 && y / goal[1] == z / goal[2]) {
          found = true;
        }
      }
      else if (goal[1] == 0) {
        if (y == 0 && x > 0 && z > 0 && x / goal[0] == z / goal[2]) {
          found = true;
        }
      }
      else if (goal[2] == 0) {
        if (z == 0 && x > 0 && y > 0 && x / goal[0] == y / goal[1]) {
          found = true;
        }
      }
      else if (x > 0 && y > 0 && z > 0) { // all non zero
        if ((x / goal[0] == y / goal[1]) && (y / goal[1] == z / goal[2])) {
          found = true;
        }
      }
      if (found && !stop) {
        for (int i = 0; i < 3; i++) {
            ans[i] = p[i];
        }
        ans[3] = x / goal[0]; // i guess casework promises goal[0] != 0 up to this point
        stop = true;
      }
    }
    }
    }
    return;
  }
  else {
    for (int i = 0; i <= 100; i++) {
        p.push_back(i);
        search();
        p.pop_back();
    }
  }
}

int main() {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    cin >> goal[0] >> goal[1] >> goal[2];
    for (int i = 0; i < 3; i++) 
      for (int j = 0; j < 3; j++)
        cin >> mix[i][j];
    search(); // brute force 101*101*101=~1e6 permutations
    if (stop) { // search stops on first find
      for (int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
      }
      cout << ans[3] << endl; 
    }
    else { 
      cout << "NONE" << endl;
    }

    return 0;
}

// so the official solution is cleaner but the same idea
// alt official solution uses matrix multiplication and cramer's rule

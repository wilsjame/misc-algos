#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int X;
    cin >> X;
    int d, j;
    d = j = 1;
    while (d < X) {
        j++;
        d = j * (j + 1) / 2;
        //printf("d: %d j: %d\n", d, j);
    }
    cout << j;

    return 0;
}


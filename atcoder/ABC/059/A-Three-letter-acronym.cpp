#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string s1, s2, s3, ans;
    cin >> s1 >> s2 >> s3;
    int dif = 'A' - 'a';
    printf("%c%c%c\n", s1[0] + dif, s2[0] + dif, s3[0] + dif);

    return 0;
}

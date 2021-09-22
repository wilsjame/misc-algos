/*
ID: jgwilso1
PROG: preface
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

string romannum(int n) {
    string s;
    for (int i = 0; i < n/1000; i++) s += 'M';
    n %= 1000;
    for (int i = 0; i < n/900; i++) s += "CM";
    n %= 900;
    for (int i = 0; i < n/500; i++) s += 'D';
    n %= 500;
    for (int i = 0; i < n/400; i++) s += "CD";
    n %= 400;
    for (int i = 0; i < n/100; i++) s += 'C';
    n %= 100;
    for (int i = 0; i < n/90; i++) s += "XC";
    n %= 90;
    for (int i = 0; i < n/50; i++) s += 'L';
    n %= 50;
    for (int i = 0; i < n/40; i++) s += "XL";
    n %= 40;
    for (int i = 0; i < n/10; i++) s += 'X';
    n %= 10;
    for (int i = 0; i < n/9; i++) s += "IX";
    n %= 9;
    for (int i = 0; i < n/5; i++) s += 'V';
    n %= 5;
    for (int i = 0; i < n/4; i++) s += "IV";
    n %= 4;
    for (int i = 0; i < n; i++) s += 'I';
    n %= 1;

    return s;
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    int n;
    cin >> n;
    unordered_map<char, int> m;
    for (int i = 1; i <= n; i++) {
        for (char c : romannum(i))
            m[c]++;
    }
    char numeral[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for (int i = 0; i < 7; i++) {
        if (m[numeral[i]] > 0)
            cout << numeral[i] << " " << m[numeral[i]] << endl;
    }

    return 0;
}

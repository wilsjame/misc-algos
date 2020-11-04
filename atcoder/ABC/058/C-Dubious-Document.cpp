#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 55;

int main() {
    int N;
    cin >> N;
    string smallest(INF, '0');
    vector<int> cnt(26, INF);
    vector<string> A(N);
    for (auto &k : A) {
        cin >> k;
        if (k.size() < smallest.size()) 
            smallest = k;
    }

    // get minimum character counts greater than zero
    for (string s : A) 
        for (char c : s)
            cnt[c - 'a'] = min(cnt[c - 'a'], (int)count(s.begin(), s.end(), c));

    // ignore characters not present in all strings
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == INF) 
            cnt[i] = 0;
        for (string s : A) 
            if ((int)count(s.begin(), s.end(), char(i + 'a')) == 0) 
                cnt[i] = 0;
    }

    for (int i = 0; i < 26; i++) 
        for (int j = 0; j < cnt[i]; j++) 
            cout << char(i + 'a');

    return 0; 
}

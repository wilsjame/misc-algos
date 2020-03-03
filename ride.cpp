/*
ID: jgwilso1
PROG: ride
LANG: C++                 
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    string comet;
    string group;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int comet_id = 1;
    int group_id = 1;
    map<char,int> hashtable;

    getline(cin, comet);
    getline(cin, group);
    
    for (int i = 0; i < 26; i++) {
        hashtable[alphabet[i]] = (i + 1);
    }
    for (auto c : comet) {
        comet_id *= hashtable[c];
    }
    for (auto c : group) {
        group_id *= hashtable[c];
    }
    if (comet_id % 47 == group_id % 47) {
        cout << "GO\n";
    }
    else {
        cout << "STAY\n"; 
    }

    return 0;
}

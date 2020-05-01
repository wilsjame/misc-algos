/*
ID: jgwilso1
PROG: namenum
LANG: C++                 
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    cerr << "%%%%%_program start_%%%%%\n";
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    long long brand;
    vector<vector<char>> chars;
    map<int,vector<char>> m;
    string name;
    vector<string> name_pool;
    m[2] = {'A','B','C'};
    m[3] = {'D','E','F'};
    m[4] = {'G','H','I'};
    m[5] = {'J','K','L'};
    m[6] = {'M','N','O'};
    m[7] = {'P','R','S'};
    m[8] = {'T','U','V'};
    m[9] = {'W','X','Y'};

    cin >> brand;
    while (brand != 0) {
        int  keypad =  brand % 10;
        chars.insert(chars.begin(), m[keypad]);
        brand /= 10;
    }
    freopen("dict.txt","r",stdin);
    while (cin >> name) {
        if (name.size() == chars.size()) {
            name_pool.push_back(name);
        }
    }
    // We know the names are the correct length
    // but what about their letters? 
    for (int k=0; k<name_pool.size(); ++k) {
        name = name_pool[k];
        // Sieve out remaining names with any
        // letters that don't match the keypad.
        for (int i=0; i<chars.size(); ++i) {
            char letter = name[i];
            if (letter != chars[i][0] && letter != chars[i][1] && letter != chars[i][2]) {
                name_pool.erase(name_pool.begin()+k); // Costly yes, the shifting can add up :/
                --k; // otherwise for loop skips an element
                break;
            }
        }
    }
    if (name_pool.empty()) {
        cout << "NONE" << endl;
    }
    else {
        for (auto const& result : name_pool) {
            cout << result << endl;
        }
    }
    return 0;
}

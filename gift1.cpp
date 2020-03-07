/*
ID: jgwilso1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct group_member {
    string name;
    int gift_money;
    int balance;
    vector<string> friends;
    group_member(string name) : name(name), gift_money(0), balance(0), friends({}) {}
};

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int NP = 0;
    int person = 0; 
    int gift_portion = 0;
    string gift_money = "";
    string num_of_friends = "";
    vector<group_member> group;

    /*** Read Input ***/
    // number of people
    string s = "";
    getline(cin, s);
    NP = stoi(s);

    // their names
    for (int i = 0; i < NP; i++) {
        getline(cin, s);
        group.push_back(group_member(s));
    }
    
    // gifting information e.g. person, $, and friends
    while (person < NP) { 

        // person index in the group
        getline(cin, s); // person's name
        int person_ID = 0; 
        for (auto p: group) {
            if (p.name == s) {break;}
            person_ID++;
        }

        // gift money and number of friends
        getline(cin, s); // $ #friends 
        stringstream str_stream(s);
        str_stream >> gift_money;
        str_stream >> num_of_friends;
        group[person_ID].gift_money = stoi(gift_money);

        // their friends
        for (int i = 0; i < stoi(num_of_friends); i++) {
            getline(cin, s); // friend
            group[person_ID].friends.push_back(s);
        }

        person++;
    }

    /*** Calculate Final Balances ***/
    for (auto &p : group) {

        if (p.friends.size() > 0) {
            gift_portion = (p.gift_money / p.friends.size());
            p.balance -= (gift_portion * p.friends.size());

            for (auto friends_name : p.friends) {
                for (auto &recipient : group) {
                    if (friends_name == recipient.name) {
                        recipient.balance += gift_portion;
                    }
                }
            }

        }

    }

    /*** Results ***/
    for (auto p : group) {
        cout << p.name << " " << p.balance << '\n';
    }

    return 0;
}

/*
ID: jgwilso1
PROG: crypt1
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// returns true if each digit of n is in the valid set
bool validcombo(int n, set<int> validset) {
    while (n) {
        int digit = n % 10;
        if (validset.count(digit) < 1) {
                return false;
        }
        n = n / 10;
    }
    return true;
}

/*

         a b c      <-- number 'abc'
        x   d e     <-- number 'de'; the 'x' means 'multiply'
     -----------
 p1      * * * *    <-- product of e * abc; first star might be 0 (absent)
 p2    * * * *      <-- product of d * abc; first star might be 0 (absent)
     -----------
 p3    * * * * *    <-- sum of p1 and p2 (e*abc + 10*d*abc) == de*abc}

*/
bool multiply(vector<int>& numscombo, set<int> validset) {
    int a, b, c, d, e, abc, p1, p2, p3;
    a = numscombo[0];
    b = numscombo[1];
    c = numscombo[2];
    d = numscombo[3];
    e = numscombo[4];
    abc = 100 * a + 10 * b + c;

    // up until here numbers were guaranteed to be valid,
    // but now the product of these numbers may be invalid.
    p1 = e * abc;
    if (p1 > 999 || p1 < 100 || !validcombo(p1, validset)) {return false;} 

    p2 = d * abc;
    if (p2 > 999 || p2 < 100 || !validcombo(p2, validset)) {return false;} 

    p3 = p1 + 10*p2;
    if (p3 > 9999 || p3 < 1000 || !validcombo(p3, validset)) {return false;} 
    return true ;
}


int main() {
    cerr << "___program start___\n";
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int num_digits, n, result = 0;
    vector<int> digits;
    set<int> valid_nums;

    cin >> num_digits;
    while (cin >> n) {  
        digits.push_back(n);
        valid_nums.insert(n);
    }
    
    int counter = 0;
    for (auto const& a : digits) {
        for (auto const& b : digits) {
            for (auto const& c : digits) {
                for (auto const& d : digits) {
                    for (auto const& e : digits) {
                        vector<int> v = {a, b, c, d, e};
                        if (multiply(v, valid_nums)) {
                            result++;
                        }
                    }
                }
            }
        }
    }

    cerr << result << endl;
    cout << result << endl;

    return 0;
}

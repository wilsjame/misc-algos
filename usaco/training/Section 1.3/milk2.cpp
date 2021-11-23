/* 
ID: jgwils01
PROG: milk2
LANG: C++
 */

#define NDEBUG
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortSchedules(const vector<int>& m, const vector<int>& n) {
    return m[0] < n[0];
}

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int N, time_in, time_out; 
    int atleast_one_cow = 0;
    int no_cow = 0;
    int shift_length = 0;
    int gap_length = 0;
    vector<vector<int>> schedules;

    cin >> N;
    while (cin >> time_in >> time_out) {
        schedules.push_back({time_in, time_out});
    }

    // sort by start times in ascending order O(nlog(n))
    sort(schedules.begin(), schedules.end(), sortSchedules);

    // edge case where first farmer covers entire time
    atleast_one_cow = schedules[0][1] - schedules[0][0];

    /* Algorithm O(n) one pass 
     * check if shift has gaps on both ends
     *  if it does, calculate shift length and 
     *  find next shift's start and calculate gap length
     * else check if next shift is completely contained by current shift
     *  if so, erase next shift
     * else next shift must be overlapping current shift
     *  assert and update current shift's end with next shift's end
     *  and erase next shift
     */
    for (int i = 0; i < schedules.size() - 1; i++) {
        if (schedules[i+1][0] > schedules[i][1]) {
            // shift has gaps on both ends
            shift_length = schedules[i][1] - schedules[i][0];
            if (shift_length > atleast_one_cow) {
                atleast_one_cow = shift_length;
            }
            gap_length = schedules[i+1][0] - schedules[i][1];
            if (gap_length > no_cow) {
                no_cow = gap_length;
            }
        }
        else if (schedules[i+1][0] < schedules[i][1] &&
                 schedules[i+1][1] <= schedules[i][1]) {
            // next shift is completely contained by current shift
            schedules.erase(schedules.begin() + (i+1)); 
            i--;
        }
        else {
            // next shift is overlapping
            assert(schedules[i+1][0] >= schedules[i][0]);
            assert(schedules[i+1][0] <= schedules[i][1]);
            assert(schedules[i+1][1] > schedules[i][1]);

            // combine next shift with current shift
            schedules[i][1] = schedules[i+1][1];
            shift_length = schedules[i][1] - schedules[i][0];
            if (shift_length > atleast_one_cow) {
                atleast_one_cow = shift_length;
            }
            schedules.erase(schedules.begin() + (i+1)); 
            i--;
        }
    }
    cout << atleast_one_cow << " " << no_cow << endl;

    return 0;
}

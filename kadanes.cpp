/* Implementation of Kadane's Algorithm for finding
* the maximum subarray sum in O(n) time. The algorithm
* leverages these truths: The maximum subarray sum
* at index [i] is 1) the value at [i] or 2) the value at
* index [i] plus the maximum sum at [i-1]. Find the max sum
* at each index in the array and store the highest. When the
* the end of the array is reached, the highest stored sum 
* is the maximum subarray sum for the range in question (e.g. 
* the entire array) */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int subSum(vector<int>& nums) {
		int best = 0, sum = 0;
		
		for (int k = 0; k < nums.size(); k++) {
			sum = max(nums[k], sum+nums[k]);
			best = max(best, sum);
		}
	
		return best;
	}
};

int main() {
	Solution solution;

	vector<int> input = {-1, 2, 4, -3, 5, 2, -5, 2};
	int expected_ans = 10;
	assert(solution.subSum(input) == expected_ans);

	return 0;
}

# Implementation of Kadane's Algorithm for finding
# the maximum subarray sum in O(n) time. The algorithm
# leverages these truths: The maximum subarray sum
# at index [i] is 1) the value at [i] or 2) the value at
# index [i] plus the maximum sum at [i-1]. Find the max sum
# at each index in the array and store the highest. When the
# the end of the array is reached, the highest stored sum 
# is the maximum subarray sum for the range in question (e.g. 
# the entire array)
from typing import List

class Solution:
	def subSum(nums: List[int]) -> int:
		sum = 0
		best = 0
		for i in range(len(nums)):
			sum = max(nums[i], nums[i]+sum)
			best = max(sum, best)
		return best

solution = Solution
input = [-1, 2, 4, -3, 5, 2, -5, 2]
expected_ans = 10
assert solution.subSum(input) == expected_ans

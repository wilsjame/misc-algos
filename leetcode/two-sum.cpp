class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        
        m[nums[0]] = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            int c = target - nums[i];
            if (m.count(c) > 0) {
                res = {m[c], i};
                break;
            }
            m[nums[i]] = i;
        }
        
        return res;
    }
};
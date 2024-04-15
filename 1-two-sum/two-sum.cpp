class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int more = target - a;
            if (numMap.find(more)!=numMap.end()) {
                return {numMap[more], i};
            }
            numMap[a] = i;
        }

        return {}; // No solution found
    }
};
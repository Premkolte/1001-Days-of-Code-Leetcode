class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return cal(nums, target, 0, 0);
    }

    int cal(vector<int>& nums, int tar, int idx, int currSum) {
        if (idx == nums.size()) {
            return (currSum == tar) ? 1 : 0;
        }

        int add = cal(nums, tar, idx + 1, currSum + nums[idx]);
        int sub = cal(nums, tar, idx + 1, currSum - nums[idx]);

        return add + sub;
    }
};
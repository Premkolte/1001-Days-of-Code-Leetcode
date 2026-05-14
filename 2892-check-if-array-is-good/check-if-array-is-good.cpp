class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        bool dup = 0;

        for (auto& num : nums) {
            int val = abs(num);
            if (val > n) return false;

            if (nums[val - 1] < 0) {
                if (val < n || dup) return false;
                dup |= 1;
                continue;
            }

            nums[val - 1] = -nums[val - 1];
        }

        return true;
    }
};
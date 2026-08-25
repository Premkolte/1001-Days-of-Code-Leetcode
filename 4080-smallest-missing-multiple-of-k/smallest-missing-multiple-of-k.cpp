class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int cur = k;
        while (seen.count(cur)) {
            cur += k;
        }

        return cur;
    }
};
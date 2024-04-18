class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // std::ios::sync_with_stdio(0);
        // std::cin.tie(0);
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0;
        }

        return maxi;
    }
};
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7; // Modulo to prevent overflow
        vector<int> dp(high + 1, 0); // DP array to store the number of ways to create strings of length i
        dp[0] = 1; // Base case: One way to create an empty string
        int result = 0; // To store the total number of good strings

        // Fill the DP array
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % MOD;
            if (i >= low) result = (result + dp[i]) % MOD;
        }

        return result;
    }
};
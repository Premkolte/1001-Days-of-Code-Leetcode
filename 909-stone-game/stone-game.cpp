class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        vector<int> dp(n);

        // Current interval length.
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                // Pick left or right pile.
                dp[i] = max(
                    piles[i] - dp[i + 1],
                    piles[j] - dp[i]
                );
            }
        }

        return dp[0] > 0;
    }
};
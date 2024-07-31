class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int remaining_width = shelfWidth, current_height = 0;
            for (int j = i-1; j >= 0; j--) {
                remaining_width -= books[j][0];
                if (remaining_width <0) break;
                current_height = max(current_height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + current_height);
            }
        }

        return dp[n];
    }
};




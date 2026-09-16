class Solution {
public:
    int bns(vector<int>& prices,int n, int i, int k, vector<vector<int>> &dp){
        if(i==n) return 0;

        if(k==0) return 0;

        if(dp[i][k] != -1) return dp[i][k];
        if(k%2==0){                                            // check if k%2==0
            int c1 = bns(prices, n, i+1, k-1, dp) - prices[i]; //buy
            int c2 = bns(prices, n, i+1, k, dp);

            return dp[i][k] =  max(c1,c2);
        }
        else{
            int c1 = bns(prices, n, i+1, k-1,dp) + prices[i]; // sell
            int c2 = bns(prices, n, i+1, k,dp);

            return dp[i][k] = max(c1,c2);

        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k=4;

        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
        return bns(prices, n, 0, k, dp);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int mini = prices[0];

        for(int i=1;i<prices.size();i++){
            int cost = prices[i] - mini;
            maxprofit = max(maxprofit,cost);
            mini = min(mini,prices[i]);
        }
        return maxprofit;
    }
};


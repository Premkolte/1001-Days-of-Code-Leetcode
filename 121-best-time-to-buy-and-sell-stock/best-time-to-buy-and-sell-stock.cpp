class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, mini=INT_MAX;
        for(int i:prices){
            profit=max(profit, i-mini);
            mini=min(mini,i);
        }
        return profit;
    }
};
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int cost = 0;
        char prev = colors[0];

        for (int i = 1; i < n; i++) {
            char curr = colors[i];
            if (curr == prev) {
                cost += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
            prev = curr;
        }
        return cost;
    }
};
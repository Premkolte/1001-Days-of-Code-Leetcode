class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int Prev = values[0];

        for (int j = 1; j < values.size(); j++) {
            ans = max(ans, Prev + values[j] - j);
            Prev = max(Prev, values[j] + j);
        }

        return ans;
    }
};
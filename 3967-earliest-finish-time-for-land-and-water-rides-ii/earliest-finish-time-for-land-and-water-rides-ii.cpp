class Solution {
public:
    int calFinishTime(vector<int>& ls, vector<int>& ld,
                      vector<int>& ws, vector<int>& wd) {

        int mini = INT_MAX, ans = INT_MAX;

        for (int i = 0; i < ls.size(); i++) {
            mini = min(mini, ls[i] + ld[i]);
        }

        for (int i = 0; i < ws.size(); i++) {
            int finish = max(mini, ws[i]) + wd[i];
            ans = min(ans, finish);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landFirst = calFinishTime(
            landStartTime, landDuration,
            waterStartTime, waterDuration
        );

        int waterFirst = calFinishTime(
            waterStartTime, waterDuration,
            landStartTime, landDuration
        );

        return min(landFirst, waterFirst);
    }
};
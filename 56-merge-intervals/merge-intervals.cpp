class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> res;
        vector<int> newint = intervals[0];
        res.push_back(newint);

        for ( vector<int>& interval : intervals) {
            if (interval[0]<=newint[1]){
                newint[1] = max(newint[1], interval[1]);
                res.back()[1] = newint[1];
            }
            else{
                newint = interval;
                res.push_back(newint);

            }
        }

        return res;
    }
};
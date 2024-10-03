class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> uniqueEle;
        unordered_map<int, int> nummap;
        for (auto num : arr) {
            uniqueEle.insert(num);
        }
        
        int rank = 1;
        for (auto ele : uniqueEle) {
            nummap[ele] = rank++;
        }

        int n = arr.size();
        vector<int> ranks(n);
        for (int i = 0; i < n; i++) {
            ranks[i] = nummap[arr[i]];
        }
        return ranks;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> unqEle;
        unordered_map<int, int> numRankMp;
        for (auto num : arr) {
            unqEle.insert(num);
        }
        
        int rank = 1;
        for (auto ele : unqEle) {
            numRankMp[ele] = rank++;
        }

        int size = arr.size();
        vector<int> ranks(size);
        for (int indx = 0; indx < size; indx++) {
            ranks[indx] = numRankMp[arr[indx]];
        }
        return ranks;
    }
};
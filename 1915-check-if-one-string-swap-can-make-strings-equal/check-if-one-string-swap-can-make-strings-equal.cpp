class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        vector<int> swapIndex;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                swapIndex.emplace_back(i);
            }
        }
        if (swapIndex.size() == 2) {
            int i = swapIndex[0], j = swapIndex[1];
            return (s1[i] == s2[j] && s1[j] == s2[i]);
        }return false;
    }
};
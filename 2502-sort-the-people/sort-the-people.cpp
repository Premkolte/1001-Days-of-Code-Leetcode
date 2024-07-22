//resolve
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> indices(heights.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return heights[i] > heights[j]; });
        vector<string> sortedNames(indices.size());
        transform(indices.begin(), indices.end(), sortedNames.begin(), [&](int i) { return names[i]; });
        return sortedNames;
    }
};
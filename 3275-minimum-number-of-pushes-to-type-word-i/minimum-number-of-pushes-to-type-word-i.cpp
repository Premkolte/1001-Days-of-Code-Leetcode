class Solution {
public:
    int minimumPushes(string& word) {
        auto [q, r]=div(word.size(), 8);
        return r*(q+1)+q*(q+1)*4;
    }
};
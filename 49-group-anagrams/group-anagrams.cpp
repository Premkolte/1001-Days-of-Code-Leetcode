class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> v;

        for(string i : strs){
            string sorted = i;
            sort(sorted.begin(),sorted.end());
            mpp[sorted].push_back(i);
        }

        for(auto &it : mpp) {
            v.push_back(it.second);
        }  

        return v; 

    }
};
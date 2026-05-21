class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        unordered_map<string, int> prefixMap;
        for (auto const& num : arr1) {
            string str1 = to_string(num);
            string prefix = "";
            for (auto const& ch : str1) {
                prefix += ch;
                prefixMap[prefix]++;
            }
        }

        int maxi = 0;
        for (auto const& num : arr2) {
            string str2 = to_string(num);
            string prefix = "";
            for (auto const& ch : str2) {
                prefix += ch;
                if (prefixMap.count(prefix) > 0) {
                    maxi = max(maxi, (int)prefix.size());
                }
            }
        }
        return maxi;
    }
};
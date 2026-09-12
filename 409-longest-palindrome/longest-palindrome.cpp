class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        if(s.length()==1) return 1;

        int cnt=0;
        // int maxu=0;
        for(auto i:mp){
            if(i.second % 2==0){
                cnt += i.second;
            }
            else{
                cnt += i.second-1;
            }
        }


        return cnt < s.size() ? cnt + 1 : cnt;


    }
};
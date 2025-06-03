class Solution {
public:
    int countSegments(string s) {
        unordered_map<string,int>mpp;
        int count=0;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                ans+=s[i];
            }
            else if(s[i]==' '){
                if(ans.length() != 0){
                    mpp[ans]++;
                    ans="";  
                }
            }
        }
        if(ans.length()!=0) mpp[ans]++;
        for(auto it:mpp){
            count += it.second;
        }
        return count;
    }
};
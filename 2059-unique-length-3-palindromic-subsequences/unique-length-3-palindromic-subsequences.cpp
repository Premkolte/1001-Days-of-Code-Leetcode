class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> start(26,-1),end(26,n); // first and last character index
        for(int i=0;i<n;i++){
            if(start[s[i]-'a']==-1) start[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(start[i]!=-1 && end[i]!=n){ // if character is not present
                unordered_set<int> st;
                for(int j=start[i]+1;j<end[i];j++) st.insert(s[j]);
                ans+= st.size();
            }
        }
        return ans;
    }
};
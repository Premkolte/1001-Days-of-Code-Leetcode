class Solution {
public:
    int maxDepth(string s) {
        int o=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                o++;
            }
            else if(s[i] == ')'){
                o--;
            }

            ans = max(ans, o);
        }

        return ans;
    }


};
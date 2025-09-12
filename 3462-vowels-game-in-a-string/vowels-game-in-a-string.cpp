class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                cnt++;
            }
        }
        if(cnt){
            return true;
        }
        else{
            return false;
        }
    }
};
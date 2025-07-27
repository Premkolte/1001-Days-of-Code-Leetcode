class Solution {
public:
    bool palindrome(string s){
        int i=0, j=s.length()-1;

        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    bool isPalindrome(string s) {
            string ps;
        for(int i=0;i<s.length();i++){
            int a=s[i];
            if((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 48 && a <= 57)){
                ps.push_back(tolower(s[i]));
            }


        }
        return palindrome(ps);
    }
};
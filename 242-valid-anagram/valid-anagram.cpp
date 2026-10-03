class Solution {
public:
    bool isAnagram(string s, string t) {
        int hashmaps[26];

        for(int i=0;i<s.size();i++){
            hashmaps[s[i] - 'a']++;
        }

        for(int i=0;i<t.size();i++){
            hashmaps[t[i] - 'a']--;
        }

        bool flag = true;

        for(int i=0;i<26;i++){
            if(hashmaps[i]!=0){
                flag = false;
                return flag;
            }
        }
        
        return flag;


    }
};
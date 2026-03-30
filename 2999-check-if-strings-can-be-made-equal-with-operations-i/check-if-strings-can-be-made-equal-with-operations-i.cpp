class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};

        for(int i=0;i<4;i++){
            if(i==0 || i==2){
                even[s1[i]-'a']++;
                even[s2[i]-'a']--;
            }
            else{
                odd[s1[i]-'a']++;
                odd[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(even[i]!=0 || odd[i]!=0){
                return false;
            }
            
        }

        return true;
    }
};
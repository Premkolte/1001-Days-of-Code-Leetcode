class Solution {
public:
    int maxFreqSum(string s) {
        int hash[26]={0};

        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']++;
        }

        int conmax=0,volmax=0;

        for(int i=0;i<26;i++){
            if(i==0||i==4|| i==8||i==14||i==20){
                volmax = max(volmax,hash[i]);
            }
            else{
                conmax = max(conmax,hash[i]);
            }
        }

        return (volmax+conmax);
    }
};
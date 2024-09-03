class Solution {
public:
    int getLucky(string s, int k) {
        string a="";
        for(int i=0;i<s.size();i++){
            a+=to_string(s[i]-96);
        }
        
        int c=0;
        while(k){
            c=0;
            for(char b : a){
                c=c+(b-'0');
            }
            k--;
            a=to_string(c);
        }

        return c;
    }
};
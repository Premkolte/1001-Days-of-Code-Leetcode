class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;

        int n= s.length();
        int h = n%k;
        for(int i=0;i<n;i=i+k){
            string m = s.substr(i,k);
            while(m.length()<k) m += fill;
            v.push_back(m);
        }

        return v;
    }
};
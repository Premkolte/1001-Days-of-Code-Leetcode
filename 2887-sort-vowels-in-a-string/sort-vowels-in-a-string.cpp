class Solution {
public:
    string sortVowels(string s) {

        vector<char> v;
        vector<int> ind;

        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                v.push_back(s[i]);
                ind.push_back(i);
            }
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < ind.size(); i++) {
            s[ind[i]] = v[i];
        }

        return s;
    }
};
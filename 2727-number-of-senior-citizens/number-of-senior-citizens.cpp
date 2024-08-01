#include<string>
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int c=0;
        for(int i=0;i<n;i++){
            string s=details[i].substr(11,2);
            if(s>"60") c++;

        }
        return c;

    }
};
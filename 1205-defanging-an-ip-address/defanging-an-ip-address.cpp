class Solution {
public:
    string defangIPaddr(string address) {
        string s="";
        for(char &p : address){
            if(p=='.'){
                s.append("[.]");
            }
            else s.push_back(p);
        }
        return s;
    }
};
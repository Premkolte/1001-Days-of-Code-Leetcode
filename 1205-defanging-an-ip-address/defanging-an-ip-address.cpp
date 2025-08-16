class Solution {
public:
    string defangIPaddr(string address) {
        string s="";
        for(char &p : address){
            if(p=='.'){
                s.push_back('[');
                s.push_back('.');
                s.push_back(']');
            }
            else s.push_back(p);
        }
        return s;
    }
};
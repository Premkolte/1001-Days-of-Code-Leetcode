class Solution {
public:
    void make(int ind,string digits,string arr[],string carry,vector<string> &res){
        if(ind==digits.size()){
            res.push_back(carry);
            return;
        }
        int temp=digits[ind]-'0'-2;//or we can add two empty strings down there
        for(int i=0;i<arr[temp].size();i++){
            make(ind+1,digits,arr,carry+arr[temp][i],res);
        }
    }
    vector<string> letterCombinations(string digits) {
        string arr[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string carry="";
        make(0,digits,arr,carry,res);
        return res;
    }
};
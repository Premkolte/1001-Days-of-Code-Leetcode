class Solution {
public:
    /*  
    use stack : as the token is in postfix notation, we. can use stack to evaluate and perform
    operations.  
    */
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto tok: tokens){
            if(tok=="+" || tok=="-" || tok=="*" || tok=="/"){
                int ans;
                int two = s.top();
                s.pop();
                int one = s.top();
                s.pop();
                if(tok=="+") ans= one + two;
                else if(tok=="-") ans= one - two;
                else if(tok=="*") ans= one * two;
                else if(tok=="/") ans= one / two;
                s.push(ans);
            }else{
                s.push(stoi(tok));
            }
            
        }
        return s.top();
    }
};
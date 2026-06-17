class Solution {
public:
    char processStr(string s, long long k) {
        vector<pair<char, long long>> opss;
        long long len =0;

        for(char ch:s){
            if(islower(ch)){
                len++;
                opss.push_back({ch,len});
            }
            else if(ch == '*'){
                if(len>0) len--;
                opss.push_back({'*',len});
            }
            else if(ch == '#'){
                len = min(len*2, (long long)1e15 +1);
                opss.push_back({'#', len});
            }
            else if(ch == '%'){
                opss.push_back({'%', len});
            }
        }
        

            if(k>=len) return '.';

        bool revv = false;

        for(int i = opss.size()-1;i>=0;--i){
            char ch = opss[i].first;
            long long currlenn = opss[i].second;

            if(islower(ch)){
                if(k==currlenn - 1){ return ch;}
            }
            else if(ch == '#'){
                currlenn /=2;
                if(k>=currlenn){
                    k -= currlenn;
                }
            }
            else if(ch == '%'){
                k=opss[i].second-1-k;
            }
        }

        return '.';
    }
};
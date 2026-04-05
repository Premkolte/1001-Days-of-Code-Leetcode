class Solution {
public:
    bool judgeCircle(string moves) {
        int c1=0;
        int c2=0;
        for(int i=0;i<moves.size();i++){
             if(moves[i]=='L') c1++;
             if(moves[i]=='R') c1--;
             if(moves[i]=='U') c2++;
             if(moves[i]=='D') c2--;
        }
        if(c1==0 && c2==0) return true;
        else return false;
    }
};
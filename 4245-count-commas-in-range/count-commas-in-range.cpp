class Solution {
public:
    int countCommas(int n) {
        int m=n;
        int cnt=0;
        while(n>0){
            cnt++;
            n=n/10;
        }

        if(cnt<4) return 0;
        else{
            int q = (m-999) ;
            return q;
        }
    }
};
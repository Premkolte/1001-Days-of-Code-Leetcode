constexpr int N=1e5+1;
bitset<N> dp;
class Solution {
public:
    static void pre_comp(){
        if (dp[1]) return;
        for (int i=1; i<N; i++) {
            for (int k=1; k*k<=i; k++) {
                if (dp[i-k*k]==0) {
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    static bool winnerSquareGame(int n) {
        pre_comp();
        return dp[n];
    }
};



auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    unordered_map<int,int> dp;
    int fib(int n) {
        // if(n==0) return 0;
        // if(n==1) return 1;

        // if(dp.find(n) != dp.end()){
        //     return dp[n];
        // }

        // int a1=fib(n-1);
        // int a2=fib(n-2);

        // int ans = a1+a2;
        // dp[n] = ans;

        // return ans;

        if(n==0 || n==1) return n;

        int prev=1;
        int prevprev=0;
        int ans=0;

        for(int i=2;i<=n;i++){
            ans=prev+prevprev;
            prevprev=prev;
            prev = ans;
        }

        return ans;
    }
};
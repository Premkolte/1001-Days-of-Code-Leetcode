class Solution {
public:
    int fn(vector<int> &nums,int n, int i, int free, vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }

        //dp
        if(dp[i][free]!=-1){
            return dp[i][free];
        }

        if(free == 0){
            return dp[i][free] =fn(nums,n, i+1, 1,dp);
        }

        int c1 = nums[i] + fn(nums, n, i+1,0,dp);
        int c2 = fn(nums, n, i+1,1,dp);

        return dp[i][free] = max(c1,c2);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int free = 1;

        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++){
            vector<int> t(2,-1);
            dp[i]=t;

        }

        return fn(nums,n,i,free, dp);
    } 
};
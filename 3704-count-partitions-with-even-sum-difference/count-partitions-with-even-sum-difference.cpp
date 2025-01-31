class Solution {
public:
    int sum(int i, int j,vector<int>& nums){
        int su=0;
        for(int k=i;k<=j;k++){
            su = su + nums[k];
        }
        return su;
    }
    int countPartitions(vector<int>& nums) {
        int cnt=0;
        int n = nums.size();

        int a=0,b=0;
        for(int i=1;i<=n-1;i++){
            a=sum(0,i,nums);
            b=sum(i+1,n-1,nums);

            int p = abs(a-b);
            if(p%2==0) cnt++;
            // cout<<a<<b<<endl;
        }
        return cnt;

    }
};
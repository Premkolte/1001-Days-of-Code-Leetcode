class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        const int n=nums.size();
    //    vector<int> ans(n);// no need
        int lsum=0, rsum=accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<n; i++){
            const int x=nums[i];
            rsum-=x;
            nums[i]=(rsum>=lsum)?rsum-lsum:lsum-rsum;// reuse
            lsum+=x;
        }
        return nums;
    }
};
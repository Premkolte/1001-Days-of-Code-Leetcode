class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left = start, right = start;
        int mini = INT_MAX;
        while(left>=0){
            if(nums[left]==target){
                mini = min(mini, start-left);
            }
            left--;
        }
        while(right<nums.size()){
            if(nums[right]==target){
                mini = min(mini, right-start);
            }
            right++;
        }
        return mini;
    }
};
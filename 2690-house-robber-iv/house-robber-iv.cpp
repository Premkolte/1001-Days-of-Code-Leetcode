class Solution {
public:
        int minCapability(vector<int>& nums, int k , int left = 1,int right = 1e9) {
        while(left < right) { 
        int mid = (left + right) / 2, canRob = 0; 
        for(int i = 0; i < nums.size() && canRob < k; i += nums[i] <= mid ? 2 : 1) 
            canRob += nums[i] <= mid; canRob < k ? left = mid + 1 : right = mid; 
        }
    return left;
    }
};
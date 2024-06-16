class Solution {

public:
    int bs(vector<int>& nums,int low,int high,int target){
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]) return bs(nums,mid+1,high,target);
        else return bs(nums,low,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0 , high = n-1;
        return bs(nums,low,high,target);
    // while(low<=high){
    //     int mid = (low +high)/2;
    //     if(nums[mid] == target) return mid;
    //     else if(nums[mid]<target){
    //         low = mid + 1;
    //     }
    //     else{
    //         high = mid -1;
    //     }
    // }
    // return -1;
    }
};


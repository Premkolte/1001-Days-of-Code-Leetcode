class Solution {
public:
bool possible(vector<int>&nums ,int o,int mid){
    for(int i=0;i<nums.size();i++){
    if(nums[i]<=mid) continue;
    int x=ceil((double)nums[i] / mid) -1 ;
    if(o-x<0) return false;
    o-=x;
    }
    return true;
}
    int minimumSize(vector<int>& nums, int o) {
        int i=1,j=*max_element(nums.begin(),nums.end());
        while(i<j){
         int mid=i+(j-i)/2;
         if(possible(nums,o,mid)) j=mid;
         else i=mid+1;
        }
        return j;
    }
};
class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     int cnt=0;
    //     int n=nums.size();
    //     int el;
    //     for(int i=0;i<n;i++){
    //         if(cnt==0){
    //             el=nums[i];
    //             cnt++;
    //         }
    //         else if(el==nums[i]){
    //             cnt++;
    //         }
    //         else {
    //             cnt--;
    //         }

    //     }
    //     return el;
    // }

    int majorityElement(vector<int>& nums){
            int ele;
            int cnt =0;
        for(int i=0;i<nums.size();i++){

            if(cnt==0){
                ele=nums[i];
                cnt++;
            }
            else if(ele == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }

        }
            return ele;
    }
};
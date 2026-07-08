// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         vector<int> a;
//         for(auto i:nums){
//             if(i!=val){
//                 a.push_back(i);

//             }
//         }

//         for(int i=0;i<a.size();i++){
//             nums[i]=a[i];
//         }

//         return a.size();
//     }
// };


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
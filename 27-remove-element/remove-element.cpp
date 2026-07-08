class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> a;
        for(auto i:nums){
            if(i!=val){
                a.push_back(i);

            }
        }

        for(int i=0;i<a.size();i++){
            nums[i]=a[i];
        }

        return a.size();
    }
};
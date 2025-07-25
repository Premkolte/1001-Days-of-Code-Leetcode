class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int n=nums.size();
            int cnt=0;
            for(int i=0;i<n;i++){
                int a = nums[i];
                int m = to_string(a).length();

                if(m%2==0) cnt++;
            }

            return cnt;
        }
    };
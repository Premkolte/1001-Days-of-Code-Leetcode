class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> missingNumbers;

        int prevNum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            while (nums[i] != prevNum + 1) {
                missingNumbers.push_back(++prevNum);
            }

            prevNum = nums[i];
        }

        return missingNumbers;
    }
};
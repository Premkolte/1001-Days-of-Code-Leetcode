#include<bits/stdc++.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n=nums.size();
        // k%=n;
        // if (n == 0) return;
        // reverse(nums.begin(), nums.begin() + k); // 2. Reverse first k elements
        // reverse(nums.begin() + k, nums.end());   // 3. Reverse remaining elements
        // reverse(nums.begin(), nums.end());       // 1. Reverse entire array

        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};
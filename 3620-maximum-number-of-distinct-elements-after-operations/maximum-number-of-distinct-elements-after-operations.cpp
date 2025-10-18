#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        ll curr = LLONG_MIN;  // next smallest usable number
        int ans = 0;
        for (auto x : nums) {
            ll start = x - k;
            ll end = x + k;
            if (max(start, curr) <= end) {
                ans++;
                curr = max(start, curr) + 1;  // pick smallest valid unique num
            }
        }
        return ans;
    }
};
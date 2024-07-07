class Solution {
public:
    int numWaterBottles(int n, int k) {
        if (n < k) return n;
        return k + numWaterBottles(n - k + 1, k);
    }
};
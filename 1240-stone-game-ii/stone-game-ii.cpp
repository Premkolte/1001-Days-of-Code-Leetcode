class Solution {
    private:
        vector<int> sums;
        vector<vector<int>> hash;

    public:
        int stoneGameII(vector<int>& piles) {
            if (piles.empty()) {
                return 0;
            }

            int n = piles.size();
            sums.resize(n);
            sums[n - 1] = piles[n - 1];

            for (int i = n - 2; i >= 0; --i) {
                sums[i] = sums[i + 1] + piles[i];
            }

            hash.resize(n, vector<int>(n, 0));
            return func(piles, 0, 1);
        }

    private:
        int func(vector<int>& a, int i, int M) {
            if (i == a.size()) {
                return 0;
            }
            if (2 * M >= a.size() - i) {
                return sums[i];
            }
            if (hash[i][M] != 0) {
                return hash[i][M];
            }

            int minVal = INT_MAX;
            for (int x = 1; x <= 2 * M; ++x) {
                minVal = min(minVal, func(a, i + x, max(M, x)));
            }

            hash[i][M] = sums[i] - minVal;
            return hash[i][M];
        }
};
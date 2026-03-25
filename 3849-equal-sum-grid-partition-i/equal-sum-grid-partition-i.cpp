class Solution {
public:
    typedef long long ll;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<ll> rowsum(n, 0);
        vector<ll> colsum(m, 0);

        ll total = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                total += grid[i][j];
                rowsum[i] += grid[i][j];
                colsum[j] += grid[i][j];
            }
        }

        if(total % 2 != 0) return false;

        // Horizontal cut
        ll upper = 0;
        for(int i = 0; i < n - 1; i++){
            upper += rowsum[i];
            if(upper == total - upper) return true;
        }

        // Vertical cut
        ll left = 0;
        for(int j = 0; j < m - 1; j++){
            left += colsum[j];
            if(left == total - left) return true;
        }

        return false;
    }
};
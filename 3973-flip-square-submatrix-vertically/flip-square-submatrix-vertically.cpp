class Solution {
public:
    static vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int t=x, b=x+k-1; t<b; t++, b--)
            swap_ranges(grid[t].begin()+y, grid[t].begin()+y+k, grid[b].begin()+y);
        return grid;
    }
};
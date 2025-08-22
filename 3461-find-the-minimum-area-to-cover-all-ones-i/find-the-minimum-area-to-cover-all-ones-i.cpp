class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int t=n,b=-1;
        int l=m,r=-1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    l=min(l,i);
                    r=max(r,i);

                    t=min(t,j);
                    b=max(b,j);
                }
            }
        }

        return (r-l+1)*(b-t+1);
    }
};
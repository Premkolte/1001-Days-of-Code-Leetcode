class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>temp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }

        int size=temp.size();
        k=k%size;

        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());

        vector<vector<int>>result(n,(vector<int>(m,0)));
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j]=temp[idx++];
            }
        }

        return result;




        // while(k--){
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<m-1;j++){
        //             swap(grid[i][j], grid[i][j+1]);
        //         }
        //     }

        //     for(int i=0;i<n-1;i++){
        //         swap(grid[i][n-1], grid[i+1][0]);
        //     }
            
        //     swap(grid[m-1][n-1], grid[0][0]);
        // }

        // return grid;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m-1;j++){
        //         swap(grid[i][j], grid[i][j+1]);
        //     }
        // }

        // for(int i=0;i<n-1;i++){
        //     // for(int j=0;j<m;j++){
        //         swap(grid[i][n-1], grid[i+1][0]);
        //     // }
        // }

        // // for(int i=0;i<n;i++){
        // //     for(int j=0;j<m-1;j++){
        //         swap(grid[m-1][n-1], grid[0][0]);
        // //     }
        // // }
    }
};
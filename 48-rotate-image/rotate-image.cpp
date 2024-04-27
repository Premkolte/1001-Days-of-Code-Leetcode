class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;i<n;j++){
        //         swap(matrix[i][j],matrix[j][i]);
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[j][n-i-1] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=a[i][j];
            }
        }
    }
};
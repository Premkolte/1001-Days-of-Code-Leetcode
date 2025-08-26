class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        
            double ans=-1.0;
            int res=0;

        for(int i=0;i<n;i++){
            int l = dimensions[i][0], b = dimensions[i][1];
            double d = sqrt(l*l*1.0 + b*b*1.0);

            if(ans<d){
                ans=d;
                res=l*b;
            }
            else if(d==ans){
                res = max(res, l*b);
            }
        }

        return res;
    }
};
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int mi = INT_MAX;

        for(int i=0;i<arr.size()-1;i++){
            mi = min(mi, abs(arr[i]-arr[i+1]));
        }

        vector<vector<int>> ans;

        for(int i=0;i<arr.size()-1;i++){
            int diff = abs(arr[i]-arr[i+1]);
            if(diff == mi){

                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;


    }
};
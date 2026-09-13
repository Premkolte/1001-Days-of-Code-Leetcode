class Solution {
public:
    void make(vector<int>& candidates,int n,int idx, int target, vector<int> &diary, vector<vector<int>> &res, int sum){
        if(idx == n){
            if(sum== target) res.push_back(diary);
            return ;
        }
        //nahi lena haii
        make(candidates, n, idx+1, target, diary, res, sum);

        //lena hai
        if(candidates[idx] + sum <= target){
            diary.push_back(candidates[idx]);
            sum = sum+ candidates[idx];
            make(candidates, n, idx, target, diary, res, sum);
            
            //remove karo
            diary.pop_back();
            sum = sum - candidates[idx];
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum=0;
        vector<int> diary;
        vector<vector<int>> res;
        int idx = 0;

        make(candidates, n, idx, target, diary, res, sum);

        return res;
    }
};
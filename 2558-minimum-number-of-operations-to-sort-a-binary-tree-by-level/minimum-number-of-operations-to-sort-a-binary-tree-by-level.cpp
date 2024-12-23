class Solution {
public:
    int cal(vector<int> &arr) {
        int n = arr.size();
        vector<pair<int, int>> record;
        for (int i = 0; i < n; i++) record.push_back({arr[i], i});
        sort(record.begin(), record.end());
        for (int i = 0; i < n; i++) arr[record[i].second] = i;
        int res = 0;
        for (int i = 0; i < n; i++)
            while (arr[i] != i) {
                swap(arr[i], arr[arr[i]]);
                res += 1;
            }
        return res;
    }
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int ans = 0;
        int lastDeep = 0;
        vector<int> tmp;
        while (!q.empty()) {
            auto [node, deep] = q.front();
            q.pop();
            if (deep != lastDeep) {
                ans += cal(tmp);
                tmp.resize(0);
                lastDeep = deep;
            }
            tmp.push_back(node -> val);
            if (node -> left) q.push({node -> left, deep + 1});
            if (node -> right) q.push({node -> right, deep + 1});
        }
        ans += cal(tmp);
        return ans;
    }
};
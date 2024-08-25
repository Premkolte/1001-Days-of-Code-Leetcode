class Solution {
public:
    void traverse(TreeNode* root, vector<int>& res){
        if (root){
            traverse(root -> left, res);
            traverse(root -> right, res);
            res.push_back(root -> val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vector<TreeNode*> prestack;
        TreeNode* root = new TreeNode(preorder[0]);
        prestack.push_back(root);
        int pre = 1, post = 0, n = preorder.size();
        while (pre < n && post < n) {
            if (postorder[post] == prestack.back()->val) {
                prestack.pop_back();
                post++;
                continue;
            }
            TreeNode* node = new TreeNode(preorder[pre]);
            if (prestack.back()->left == NULL)
                prestack.back()->left = node;
            else
                prestack.back()->right = node;
            pre++;
            prestack.push_back(node);
            continue;
            
        }
        return root;
    }
};
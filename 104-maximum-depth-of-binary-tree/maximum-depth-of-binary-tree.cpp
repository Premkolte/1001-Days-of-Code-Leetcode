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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<TreeNode*> nodes;
        nodes.push(root);
        int levels = 0;

        while(!nodes.empty()){
            levels++;
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                TreeNode* poppedNode = nodes.front();
                nodes.pop();

                if (poppedNode->left != NULL)
                    nodes.push(poppedNode->left);
                if (poppedNode->right != NULL)
                    nodes.push(poppedNode->right);

            }
        }

        return levels;
    }
};
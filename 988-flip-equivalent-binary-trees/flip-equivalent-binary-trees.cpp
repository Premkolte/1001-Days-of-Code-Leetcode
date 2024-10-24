/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    using info = pair<TreeNode*, TreeNode*>;// info pair

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2) return 1;       
        if (!root1 || !root2 || root1->val != root2->val) return 0;

        queue<info> q;
        q.emplace(root1, root2);

        while (!q.empty()) {
            auto [node1, node2] = q.front();
            q.pop();
            //    cout<<((node1)?node1->val:-1)<<","<<((node2)?node2->val:-1)<<endl;
            if (node1 == node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return 0;

            // Get the left and right children of both nodes
            auto L1 = node1->left, L2 = node2->left;
            auto R1 = node1->right, R2 = node2->right;

            // check  non-flipped (L1 with L2 and R1 with R2)
            if (((!L1 && !L2) || (L1 && L2 && L1->val == L2->val)) &&
                ((!R1 && !R2) || (R1 && R2 && R1->val == R2->val))) 
            {
                q.emplace(L1, L2);
                q.emplace(R1, R2);
            }
            // Then, check flipped  (L1 with R2 and R1 with L2)
            else if (((!L1 && !R2) || (L1 && R2 && L1->val == R2->val)) &&
                     ((!R1 && !L2) || (R1 && L2 && R1->val == L2->val)))
            {
                q.emplace(L1, R2);
                q.emplace(R1, L2);
            } 
            else return 0;
        }
        return 1; 
    }
};
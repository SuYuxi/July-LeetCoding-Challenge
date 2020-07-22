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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> q = {root};
        bool rightToLeft = false;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                level.emplace_back(node->val);
                q.pop_front();
                if(node->left) q.emplace_back(node->left);
                if(node->right) q.emplace_back(node->right);
            }
            if(rightToLeft)
            {
                reverse(level.begin(), level.end());
            }
            res.emplace_back(level);
            rightToLeft = !rightToLeft;
        }
        return res;
    }
};

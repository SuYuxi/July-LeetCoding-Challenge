class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.empty()) return nullptr;
		int i = inorder.size() - 1, p = postorder.size() - 1;
		TreeNode* root = new TreeNode(postorder[p--]);
		stack<TreeNode*> nodeStack;
		nodeStack.push(root);
		while(i >= 0) {
			TreeNode* node = nodeStack.top();
			if(node->val != inorder[i]) {
				node->right = new TreeNode(postorder[p--]);
				nodeStack.push(node->right);
			}
			else {
				while(!nodeStack.empty() && nodeStack.top()->val == inorder[i]) {
					node = nodeStack.top();
					nodeStack.pop();
					i--;
				}
				if(i >= 0) {
					node->left = new TreeNode(postorder[p--]);
					nodeStack.push(node->left);
				}
			}
		}
		return root;
    }
};

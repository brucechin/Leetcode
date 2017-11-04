/*

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

*/

/*

递归解，每遇到一个点加进pre中，传到下一个点里，直到遇到叶子节点，把pre加入result里，为一条路径

*/
class Solution {
public:
    vector<string> result;
    void helper(TreeNode * root,string pre){
        if(!root->left && !root->right){
            result.push_back(pre);
            return ;
        }
        if(root->left){
            string left = pre + "->" + to_string(root->left->val);
            helper(root->left,left);
        }
        if(root->right){
            string right = pre+ "->" + to_string(root->right->val);
            helper(root->right,right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return result;
        string begin = to_string(root->val);
        helper(root,begin);
        return result;

    }
};


/*

DFS 非递归解

*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode*> nodes;
        stack<string> path;
        nodes.push(root);
        path.push(to_string(root->val));
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            string curpath = path.top();
            path.pop();
            if (node->left == NULL&&node->right == NULL)
                ans.push_back(curpath);
            if (node->left) {
                nodes.push(node->left);
                path.push(curpath + "->" + to_string(node->left->val));
            }
            if (node->right) {
                nodes.push(node->right);
                path.push(curpath + "->" + to_string(node->right->val));
            }
        }
        return ans;
    }
};

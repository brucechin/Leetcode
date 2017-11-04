/*

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

*/

/*

S里有一个子树和T完全相同，写一个判断完全相同的函数，遍历S的所有节点，若找不到这样的子树，就不存在

*/
class Solution {
public:
    vector<TreeNode*> record;
    void travel(TreeNode* root){
        record.push_back(root);
        if(root){
            travel(root->left);
            travel(root->right);
        }
    }
    bool identical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;

        return identical(a->left, b->left) && identical(a->right, b->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;

        travel(s);

        for (TreeNode* n: record)
            if (identical(n, t))
                return true;

        return false;
    }
};

/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

*/

/*

recursion解法里其实跟就是用判断两棵子树相同的函数，但参数换成对称的节点进行比较

non-recursion解法里加入queue的顺序需要是对称的

*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* l,TreeNode* r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val != r->val) return false;
        return isMirror(l->right,r->left) && isMirror(l->left,r->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);q.push(root->right);
        while(!q.empty()){
            TreeNode * left = q.front();q.pop();
            TreeNode * right = q.front();q.pop();
            if(!left && !right) continue;
            if(!left || !right) return false;
            if(left->val != right->val) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);//注意入队顺序，前两个相互对称，后两个也相互对称
        }
        return true;
    }

};

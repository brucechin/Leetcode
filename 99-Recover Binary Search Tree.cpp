/*

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//可以把整个node存成一个vector，再把node的值存成一个vector并排序，然后按顺序重新赋值给node的vector，但是空间复杂度O(N)。

class Solution {
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        help(root);
        swap(first->val, second->val);
    }
    
    void help(TreeNode* root){
        if(root==NULL)  return;
        help(root->left);
        if(first==NULL && prev->val > root->val)   first=prev;
        if(first!=NULL && prev->val > root->val)   second=root;
        prev=root;
        help(root->right);
    }
};

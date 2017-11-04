/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

*/

/*

递归判断两子树depth之差<=1，bottom-up的解法更优，因为自顶而下的解法，调用depth开销太大

*/
class Solution {
public:
    int depth(TreeNode *root){
        if(!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left=depth(root->left);
        int right=depth(root->right);
        return  abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right) ;
    }
};


// bottom-up的解法，因为depth是递归求深度的，从底层开始返回值之前就顺便判断是不是已经出现unbalance了，用-1作为unbalance的标记，有一个-1，整个递归过程就必定返回-1
class Solution {
public:
    int depth(TreeNode *root){
        if(!root) return 0;
        int left = depth(root->left);
        if(left == -1) return -1;
        int right = depth(root->right);
        if(right == -1) return -1;
        if(abs(left-right) >　1) return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return  depth(root) != -1 ;
    }
};

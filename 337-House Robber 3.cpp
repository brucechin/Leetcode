/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

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

//too many recursive calls which makes this implementation slow
class Solution {
public:
    int helper(TreeNode* root,map<TreeNode*,int>& record){
        if(root == NULL) return 0;
        
        if(record.find(root) != record.end()) return record[root];
        
        int val = 0;
        if(root->left != NULL){
            val += helper(root->left->left,record) + helper(root->left->right,record);
        }
        if(root->right != NULL){
            val += helper(root->right->left,record) + helper(root->right->right,record);
        }
        
        val = max(val + root->val,helper(root->left,record) + helper(root->right,record));
        record[root] = val;
        return val;
    }
    int rob(TreeNode* root) {
        map<TreeNode*, int> re;
        return helper(root, re);
    }
};
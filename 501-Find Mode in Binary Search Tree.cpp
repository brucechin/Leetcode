/*

Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

*/

/*

中序遍历，prev记录前一个点，一旦不一样，count重置，count>max时清空结果集，将该val加入，相同时把该val加入结果集

*/
class Solution {
public:
    int m = 0, count = 1;
    int prev = INT_MIN;
    void travel(TreeNode* root,vector<int>& record){
        if(!root)return;
        travel(root->left,record);

        if(prev != INT_MIN){
            if(root->val == prev){
                count++;
            }else{
                count = 1;
            }
        }
        if(count > m){
                m = count;
                record.clear();
                record.push_back(root->val);
        }else if(count == m){
                record.push_back(root->val);
        }
        prev = root->val;
        travel(root->right,record);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> record;
        travel(root,record);
        return record;
    }
};

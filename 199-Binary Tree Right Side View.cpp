/*


Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        vector<TreeNode*> travelList;
        travelList.push_back(root);
        
        while(!travelList.empty()){
            result.push_back(travelList[travelList.size()-1]->val);
            vector<TreeNode*> tmp;
            for(int i=0;i<travelList.size();i++){
                if(travelList[i]->left != NULL) tmp.push_back(travelList[i]->left);
                if(travelList[i]->right != NULL) tmp.push_back(travelList[i]->right);
            }
            
            travelList = tmp;
            
        }
        return result;
    }
};
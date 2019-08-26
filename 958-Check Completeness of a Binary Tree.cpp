/* 

Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:

Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:



Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 
Note:

The tree will have between 1 and 100 nodes.

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
    bool isCompleteTree(TreeNode* root)
    {
        if(root==NULL)
        return true;
        TreeNode *p,*r;
        std::queue<TreeNode *> q{};                   // Queue is created
        q.push(root);
        int count=0;
        while(!q.empty())                             // while q is empty it will run
        { 
            int z=q.size();
            for(int i=0;i<z;i++)
            {
            p=q.front();
            q.pop();
                if(p==NULL)                           // as soon as first null is recived all the next 
                {                                     // elements must be null in order to be a complete
                                                      // binary tree
                    count++;
                    while(!q.empty())
                    {
                        r=q.front();
                        q.pop();
                        if(r!=NULL)
                            return false;
                    }
                    break;  
                }
            q.push(p->left);
            q.push(p->right);
            }
        }
        return true;                                  // If all nodes after first null are null, it returns true;
        
    }
};
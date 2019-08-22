/*

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.


Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.


Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.

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
    vector< pair< TreeNode*,char > > a; // To store the nodes encountered in the path from root to the targetNode
    vector< int > ans;
    
    bool Find(TreeNode* currentNode,TreeNode* targetNode){
        if(currentNode == NULL)
            return 0;
        if(currentNode == targetNode)
            return 1;
        
        bool ans1=Find(currentNode->left,targetNode);
        bool ans2=Find(currentNode->right,targetNode);
        
        if(ans1 == 1)
            a.push_back(make_pair(currentNode,'L'));
        else if(ans2 == 1)
            a.push_back(make_pair(currentNode,'R'));
        
        return ans1 || ans2;
    }
    
    void dfs(TreeNode* currentNode,int k){ //This function stores all the value of all the nodes which are at a distance k from the currentNode in the vector ans

        if(currentNode == NULL || k < 0)
            return;
        if(k == 0){
            ans.push_back(currentNode->val);
            return;
        }
        dfs(currentNode->left,k-1);
        dfs(currentNode->right,k-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        Find(root,target);
        dfs(target,k);
        int n=a.size();
        
        for(int i=n-1;i>=0;i--){
            if(k-(i+1) < 0)
                continue;
            else if(k-(i+1) == 0)
                ans.push_back(a[i].first->val);
            else{
                if(a[i].second == 'L')
                    dfs(a[i].first->right,k-(i+1)-1);
                else
                    dfs(a[i].first->left,k-(i+1)-1);
            }
        }
        
        
        return ans;
    }
};
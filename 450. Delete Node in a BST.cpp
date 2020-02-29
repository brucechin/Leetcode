/*

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

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
    TreeNode* deleteNode(TreeNode* root, int key) {
    if( !root )
        return nullptr;
    
    if( root->val == key ){
        if( !root->right )
            return root->left;
        else{
            //find the next larger node than root. swap them(now the target is at leaf node). target will be deleted later
            TreeNode* n = root->right;
            while( n->left )
                n = n->left;
            swap( n->val , root->val );
            
            root->right = deleteNode( root->right , key );
            return root;
        }
    }
    
    if( root->val > key )
        root->left = deleteNode( root->left , key );
    if( root->val < key )
        root->right = deleteNode( root->right , key );
    return root;
}

    bool insertNode( TreeNode* root, int key){

        TreeNode* parent = NULL;
        TreeNode* cur = root;
        while( cur){
            if( cur->val == key ){
                return false;
            }else if( cur->val > key ){
                parent = cur;
                cur = cur->left;
            }else
            {
                parent = cur;
                cur = cur->right;
            }
            
        }
        if( parent->val > key ){
            parent->left = new TreeNode(key);
        }else{
            parent->right = new TreeNode(key);
        }
        return true;
    }
};
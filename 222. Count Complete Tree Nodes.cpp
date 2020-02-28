/*

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

*/

class Solution
{
public:
    int getLeftHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->left;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int left_height = getLeftHeight(root->left);
        int right_height = getLeftHeight(root->right);

        if (left_height == right_height)
            return pow(2, left_height) + countNodes(root->right);

        return pow(2, right_height) + countNodes(root->left);
    }
};
/*

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

*/

/*

两个recursion嵌套，一个是找该节点下有多少条这样的path，一个是遍历这个树的所有节点，并对所有节点调用前者

需要注意的是，recursion的不同写法，会造成用时的变化，不把recursion写在return里的话会快一点

*/
class Solution {
public:
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        sumUp(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return count;
    }
    void sumUp(TreeNode* root,int sum){
        if(!root) return;
        int cur = sum - root->val;
        if(cur == 0)
            count++;
        sumUp(root->left,cur);
        sumUp(root->right,cur);
    }
};

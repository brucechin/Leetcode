/*

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.
Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]

*/

void dfs(TreeNode* r, int x, int y, map<int, map<int, set<int>>> &m) {
  if (r != nullptr) {
    m[x][y].insert(r->val);
    dfs(r->left, x - 1, y + 1, m);
    dfs(r->right, x + 1, y + 1, m);
  }
}
vector<vector<int>> verticalTraversal(TreeNode* r, vector<vector<int>> res = {}) {
  map<int, map<int, set<int>>> m;//遍历的时候是按key从小到大的顺序遍历的
  dfs(r, 0, 0, m);
  for (auto itx = m.begin(); itx != m.end(); ++itx) {
      res.push_back(vector<int>());
      for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
          res.back().insert(end(res.back()), begin(ity->second), end(ity->second));//把ity->second的整个set插进res.back()末尾，也可以遍历set一个个push_back
      }
  }
  return res;
}
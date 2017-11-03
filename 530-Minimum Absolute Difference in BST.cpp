class Solution {
public:
    vector<TreeNode*> tree;
    void midTravel(TreeNode* root){
        if(!root)return;
        midTravel(root->left);
        tree.push_back(root);
        midTravel(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        midTravel(root);
        int min=INT_MAX,size = tree.size();

        for(int i=0; i<size-1; i++){
            min = min < tree[i+1]->val - tree[i]->val ? min : tree[i+1]->val - tree[i]->val;
        }
        return min;

    }
};

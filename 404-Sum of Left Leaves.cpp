class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> tmp;
        int result=0;
        tmp.push(root);
        while(!tmp.empty()){
            TreeNode * p = tmp.front();tmp.pop();

            if(p->right != NULL) tmp.push(p->right);
            if(p->left != NULL){
                if((p->left->left == NULL) && (p->left->right == NULL)){
                    result += p->left->val;
                }else{
                    tmp.push(p->left);
                }
            }
        }
        return result;

    }
};

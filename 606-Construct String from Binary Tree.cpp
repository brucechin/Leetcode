//注意一下左空右非空的情况即可
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        string s="";
        s += to_string(t->val);
        if(t->left == NULL && t->right != NULL)  s+="()";

        if(t->left) s+="("+tree2str(t->left)+")";

        if(t->right) s+="("+tree2str(t->right)+")";
        return s;

    }
};

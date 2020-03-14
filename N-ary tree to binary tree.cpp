
/*----------------------------------------------------------------
Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

For example, you may encode the following 3-ary tree to a binary tree in this way:

 



 

Note that the above is just an example which might or might not work. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Note:

N is in the range of [1, 1000]
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
*/

class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return NULL;
        TreeNode *res = new TreeNode(root->val);
        if (!root->children.empty()) {
            res->left = encode(root->children[0]);
        }
        TreeNode *cur = res->left;
        for (int i = 1; i < root->children.size(); ++i) {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return res;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return NULL;
        Node *res = new Node(root->val, {});
        TreeNode *cur = root->left;
        while (cur) {
            res->children.push_back(decode(cur));
            cur = cur->right;
        }
        return res;
    }
};
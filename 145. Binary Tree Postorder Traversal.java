/*

Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

*/

public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.add(p.val);  // Add before going to children
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            p = node.right;   
        }
    }
    return result;
}

public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            result.add(node.val);  // Add after all left children
            p = node.right;   
        }
    }
    return result;
}

public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<Integer> result = new LinkedList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.addFirst(p.val);  // Reverse the process of preorder
            p = p.right;             // Reverse the process of preorder
        } else {
            TreeNode node = stack.pop();
            p = node.left;           // Reverse the process of preorder
        }
    }
    return result;
}

//c++ 层序遍历 非递归实现
vector<int> LevelOrder(TreeNode* root)
{
    vector<int> result;//利用vector存放层序遍历序列
    queue<TreeNode*> q;

    if (root == NULL)
    {
        return result;
    }

    q.push(root);
    while (!q.empty())
    {
        TreeNode* front = q.front();
        if (front->left)
        {
            q.push(front->left);
        }

        if (front->right)
        {
            q.push(front->right);
        }

        result.push_back(front->val);
        q.pop(front);
    }
}

//c++ 前序遍历 非递归实现
vector<int> PreOrder(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> s;

    if (root == NULL)
        return result;

    while (root || !s.empty())
    {//结束遍历的条件是root为空且栈为空
        while(root)
        {//找到最左结点，并把路径上的所有结点一一访问后入栈
            s.push(root);
            result.push_back(root->val);
            root = root->left;
        }
        root = s.top();//取栈顶结点
        s.pop();//弹出栈顶结点
        root = root->right;//左和中都访问了再往右访问
    }
    return result;
}


//C++ 中序遍历 非递归实现
vector<int> InOrder(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> s;

    if (root == NULL)
        return result;

    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        result.push_back(root->val);
        s.pop();
        root = root->right;
    }
    return result;
}

//c++ 后序遍历 非递归实现
vector<int> PostOrder(TreeNode* root)
{
    vector<int> result;
    stack<int> s;
    TreeNode* cur = root;
    TreeNode* pre = NULL;

    if (root == NULL)
        return result;

    while (cur)
    {//走到最左孩子
        s.push(cur);
        cur = cur->left;
    }

    while (!s.empty())
    {
        cur = s.top();
        if (cur->right == NULL || cur->right == pre)
        {//当一个结点的右孩子为空或者被访问过的时候则表示该结点可以被访问
            result.push_back(cur->val);
            pre = cur;
            s.pop();
        }
        else
        {//否则访问右孩子
            cur = cur->right;
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
        }
    }
    return result;
}



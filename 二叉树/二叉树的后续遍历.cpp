//递归


void midOrder(TreeNode* root,vector<int> res){
    if(!root){
        return;
    }
    res.push_back(root->val);
    midOrder(root->left, res);
    midOrder(root->right, res);
}


// 迭代

void midOrder(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> stk;
    while(root!=nullptr || !stk.empty()){ // 当节点存在，并且栈不为空时循环
        while(root!=nullptr){
            stk.push(root);
            res.push_back(root->val);
            root = root->right;
        }
        root = stk.top();
        stk.pop();
        root = root->left;
    }
    return reverse(res.bigin(), res.end()s);
}
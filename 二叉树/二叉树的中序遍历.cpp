//递归


void midOrder(TreeNode* root,vector<int> res){
    if(!root){
        return;
    }
    midOrder(root->left, res);
    res.push_back(root->val);
    midOrder(root->right, res);
}


// 迭代

void midOrder(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> stk;
    while(root!=nullptr || !stk.empty()){ // 当节点存在，并且栈不为空时循环
        while(root!=nullptr){
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}
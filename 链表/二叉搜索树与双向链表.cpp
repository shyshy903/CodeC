class Solution {
public:
    Node* pre,*head;

    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        dfs(root);
        head->left=pre;//首
        pre->right=head;//尾 相接
        return head;
    }
    void dfs(Node* root){
//基例
        if(!root) return ;

        dfs(root->left);

//操作
        if(!pre) head=root;
        else pre->right=root;
        root->left=pre;
        pre=root;

        dfs(root->right);
    }
};


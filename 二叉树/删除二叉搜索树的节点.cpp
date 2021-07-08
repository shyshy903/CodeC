/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    /* 第一种情况：没找到删除的节点，遍历到空节点直接返回了 */
    if (!root) {
        return NULL;
    }
    /* 当前节点就是key */
    if (root->val == key) {
        // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
        if (!root->left) {  // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            return root->right;
        } else if (!root->right) { // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            return root->left;
        } else {// 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
                // 并返回删除节点右孩子为新的根节点。
            struct TreeNode* tmp = root->right; // 找右子树最左面的节点
            while (tmp->left) {
                tmp = tmp->left;
            }
            tmp->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
            struct TreeNode* p = root;  // 把root节点保存一下，下面来删除
            root = root->right; // 返回旧root的右孩子作为新root
            free(p);    // 释放节点内存
            return root;
        }
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int vinLen = vin.size();
        if(vinLen==0){
            return nullptr;
        }
        vector<int> preLeft, preRight, vinLeft, vinRight;
        TreeNode* head = new TreeNode(pre[0]);
        int root = 0; //找到根节点的位置
        for(int i=0; i<vinLen; i++){
            if(vin[i] == pre[0]){
                root = i;
                break;
            }
        }

        // 放入新数组
        for(int i=0; i<root; i++){
            vinLeft.push_back(vin[i]);
            preLeft.push_back(pre[i+1]);
        }
        for(int i=root+1; i<vinLen; i++){
            vinRight.push_back(vin[i]);
            preRight.push_back(pre[i]);
        }

        head->left = reConstructBinaryTree(preLeft, vinLeft);
        head->right = reConstructBinaryTree(preRight, vinRight);
        return head;
    }
};


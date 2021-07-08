// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

// 示例:

// 输入: [1,2,3,null,5,null,4]
// 输出: [1, 3, 4]
// 解释:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//层序遍历，每层输出最后一个值 相当于用BFS方法



# Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <queue>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> que;
        res.push_back(root->val);
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            queue<TreeNode*> tempq;
            while(size--){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) tempq.push(root->left);
                if(node->right) tempq.push(root->right);
            }
            res.push_back(tempq.back()->val);
            swap(tempq,que);
        }

    }
};


//时间复杂度O(N)
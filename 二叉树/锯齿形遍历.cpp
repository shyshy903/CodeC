/* 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include<iostream>
#include<queue>
#include<vector>
#include<deque>
using namespace std;


struct TreeNode
{
    /* data */
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr, right(nullptr)){};
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right){};
};

vector<vector<int>> juchioreder(TreeNode* root){
    vector<vector<int>> ans;
    if(!root){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool is_left_to_right = true;
    while(!q.empty){
        deque<int> tempq;
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if (is_left_to_right){
                tempq.push_back(node->val);
            }else{
                tempq.push_front(node->val);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    ans.push_back(vector<int> {tempq.begin(), tempq.end()});
    is_left_to_right = !is_left_to_right;
}

int main(){

}

// 时间复杂度为O(N), 每个节点都会被遍历一次
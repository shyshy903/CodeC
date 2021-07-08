// 给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

// 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

// 示例 1:

// 输入: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// 输出: 4
// 解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/maximum-width-of-binary-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 层序遍历，比较长度

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode* > temp;
        int res = 0;
        if(!root) return 0;
        temp.push(root);
        while(!temp.empty()){
            queue<TreeNode*> vec;
            for(int i = 0; i < temp.size(); i++){
                TreeNode* node = temp.front();
                temp.pop();
                if(node->left) vec.push(root);
                if(node->right) vec.push(root);
            }
            res = res > vec.size() ? res:vec.size();
            swap(temp, vec);
        }
        return res;
    }
};
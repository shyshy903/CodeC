/* 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */


#include <vector>

class Solution {

void dfs(vector<int>&nums, vector<vector<int>> &res, int first, int len){
    if(first==len){
        res.push_back(nums);
        return res;
    }
    for(int i = first; i < len; i++){
        swap(nums[i], nums[first]);
        dfs(nums, res, first+1, len);
        swap(nums[i], nums[first]);
    }

}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // vector<int> path;
        dfs(nums, res, 0, nums.size());
        return res;
    }
};


#include <vector>

class Solution {

void dfs(vector<int>&nums, vector<vector<int>> &res, vvector<int> path, int first){
    if(path.size==nums.size()){
        res.push_back(path);
    }
    for(int i = first; i < len; i++){
        path.push_back(nums[i]); // 做出选择
        dfs(nums, res, path, i+1);
        path.pop_back(nums[i]);
    }

}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int i = 0;
        dfs(nums, path, res, i)
        return res;
    }
};
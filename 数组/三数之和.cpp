/* 
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */


#include<vector>
#include<iostream>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums){
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < nums.size(); i++){
        int target = 0 - nums[i];
        int l =  i;
        int  j = n - 1;
        if(nums[i] > 0) return res;
        if(i!= 0 && nums[i] == nums[i-1]) continue;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum < target){
                l++;
            }else if (sum > target)
            {
                r--;
            }else{
                res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                l++;
                r--;
                if(nums[l] == nums[l++] && l < r) l++;
                if(nums[r] == nums[r--] && l < r) r--;
            }
        }
    }
    return res;
}

//时间复杂度O(n2)
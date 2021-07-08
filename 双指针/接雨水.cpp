/* 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int res =  0;
        int left = 0, right = height.size()-1;
        int left_max = height[0];
        int right_max = height[height.size()-1];
        while(left<right){
            if(height[left] < height[right]){
                left_max = max(height[left], left_max);
                res += left_max - height[left];
                left++;
            }else{
                right_max = max(height[right]);
                res += right_max-height[right];
                right--;
            }
        }
        return res;
};
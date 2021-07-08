/* 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */


int maxSeqSum(vector<int> &nums){
    if(nums.size()==0) return 0;
    vector<int> dp(n,0);
    dp[0] = nums[0];
    int result = dp[0];
    for(int i = 1; i < nums.size(); i++){
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        result = dp[i] > result ? dp[i] : result;
    }
    return result;
}
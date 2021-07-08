// 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

//  

// 示例：

// 输入：
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// 输出：3
// 解释：
// 长度最长的公共子数组是 [3, 2, 1] 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//动态规划

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,0));
        int res = 0;
        for(int i=1; i<=nums1.size(); i++){
            for(int j=1; j<= nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                res = max(dp[i][j], res);
            }
        }
        return res;
    }
};
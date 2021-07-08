class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for(int i = 0; i < nums.size(); i++){
            int maxLength = i + nums[i];
            for(int j = i; j < maxLength + 1; j++){
                dp[j] = min(dp[j], dp[j] + 1);
            }
        }
        return dp[nums.size()];
    }
};
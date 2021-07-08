class Solution{
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 0;
        for(int i = 0; i < coins.szie(); i++){//枚举硬币类型
            for(int j=i; j < amount+1; j++){
                dp[j] = min(dp[j-i] + 1, dp[j]);
            }
        }
        return dp[amount];
    }
};

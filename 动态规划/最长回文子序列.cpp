class Solution 
{
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 0; i < n; i ++)
            dp[i][i] = 1;
        for (int i = n - 1; i > -1; i --)       //遍历顺序是由递推关系式决定的
            for (int j = i+1; j < n; j ++)      //由关系式所得
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        return dp[0][n-1]; 
    }
};

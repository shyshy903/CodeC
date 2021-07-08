/* 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */


#include <iostream>

#include <string>



class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp;
        for(int i=0; i < l1+1; i++){
            dp[i][0] = 1;
        }
        for(int j=0; j< l2+1; j++){
            dp[o][j] = 1;
        }
        for(int i=1; i<l1+1; i++){
            for(int j = 1; j < l2+1; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]) + 1;
                if(word[i-1] == word[j-1]){
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
                }
            }
        }
        return dp[l1][l2];
    }
};
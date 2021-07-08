/* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */



#include<iostream>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<string>


using namespace std;

int getLength(string s){
    set<char> occ;
    int n = s.size();
    int rk = -1;
    int ans = 1;
    for(int i = 0; i < n; i++){
        if(i!=0){
            occ.erase(s[i]);
        }
        while(rk+1 < n && !occ.count(s[rk+1])){
            occ.insert(s[rk+1]);
            rk++;
        }
        ans = max(ans, rk-i+1);
    }
    return ans;

}


int main(){
    string s;
    cin>>s;
    getLength(s);
}
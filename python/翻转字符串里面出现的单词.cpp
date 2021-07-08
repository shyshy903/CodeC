class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))


        
class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string ans;
        while(i >= 0)
        {
            int c = 0;
            while(i >= 0 && s[i] == ' ') --i;
            while(i >= 0 && s[i] != ' ')
            {
                --i;
                ++c;
            }
            if(c)
                ans += s.substr(i+1, c) + " ";
        }

        return ans.substr(0, ans.size()-1);
    }
};

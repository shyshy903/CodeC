class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        for (int i=0; i<s.size(); i++){
            if (s[i] == ' '){
                s.replace(i,1,"%20");//从i位置开始的1个字符替换为%20
            }
        }
        return s;
    }
};

// 但是考虑到string从前往后的性能会损失，可以考虑从后往前，先申请一个大空间，再逐渐添加
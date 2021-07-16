//  我觉得可以从对角线进行分析


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();  // 行
        int n = array[0].size();  // 列
        int row = 0, col = n-1;  // 可以定位到右上角元素
        
        while(row < m && col >= 0){
            if (target == array[row][col]){
                return true;
            }else if(target > array[row][col]){
                row++;
            }else{
                col--;
            }
        }
        return false;     
    }
};

// O(m+n)
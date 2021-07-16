class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size()==0) return false;
        int first = 0;  // 定义第一个
        int last = rotateArray.size() - 1;  // 定义最后一个
        
        while(first < last){
            // 当左小于右边
            if(rotateArray[first] < rotateArray[last]){
                return rotateArray[first]
            }
            int mid = first + (last - first) >> 1;
            if(rotateArray[mid] > rotateArray[last]){
                first = mid + 1;
            }else if(rotateArray[mid] < rotateArray[last]){
                last = mid;
            }else{
                last--;
            }
        }
        return rotateArray[first]; // 返回答案
        
    }
};
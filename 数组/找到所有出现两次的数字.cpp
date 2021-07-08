
// 标记法
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int>result;
        int m = nums.size(); 
        if(m == 0) return result;
        for(int i = 0; i < m; i++)
        {
            int num = abs(nums[i]);
            if(nums[num - 1] > 0)
               nums[num - 1] *=(-1);
            else result.push_back(num);       
        }
    
    return result;
    }
};  

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(vector<int>& nums, int start) {
        // path.push_back(nums)  这里是易错点，需要多思考，回溯搜集所有节点，或者只是叶子节点，这里写法都不同哦
        result.push_back(path);
        if(start==nums.size()) {
            return;
        }

        for(int i=start;i<nums.size();i++) {
            path.push_back(nums[i]);
            backtrack(nums, i+1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};

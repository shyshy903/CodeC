/* 
给你一个整数数组 nums，请你将该数组升序排列。

 

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 */

// 其实也就是合并两个已经排序好的数组

class Solution {
public:

    vector<int> tmp;

    void mergeSort(ector<int>& nums), int l, int r){
        if (l>=r) return;
        int mid = l + (l - r) / 2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        int i = 1; j = mid + 1;
        int cnt = 0;
        while(i<=mid && j <=r){
            if(nums[i] <= nums[j]){
                tmp[cnt++] = nums[i++];
            }else{
                tmp[cnt++] = nums[j++];
            }
            while(i<=mid){
                tmp[cnt++] = nums[i++];
            }
            while(j<=r){
                tmp[cnt++] = nums[j++];
            }

        }
        nums.assign(tmp.begin(), temp.end());
    }


    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.szie()-1);
        return nums;

    }
};
//  使用双指针

        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        int slow = 0, fast = 1;
        for(fast=1; fast<nums.size(); fast++){
            if (nums[slow] == nums[fast]){
                continue;
            }
            else{
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;

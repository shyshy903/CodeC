class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r){
        if(l < r){
            int i = l, j = r;
            while(i < j){
                while(i < j && nums[j] >= nums[l]) --j;
                while(i < j && nums[i] <= nums[l]) ++i;
                swap(nums[i], nums[j]);
            }
            swap(nums[l], nums[i]);
            quick_sort(nums, l, i - 1);
            quick_sort(nums, i + 1, r);
        }
    }

    void merge(vector<int>& nums, vector<int>& tmp, int l, int r){
        int i = l, mid = l + (r - l) / 2, j = mid + 1, pos = l;
        while(i <= mid && j <= r){
            if(nums[i] < nums[j]) tmp[pos++] = nums[i++];
            else tmp[pos++] = nums[j++];
        }
        while(i <= mid) tmp[pos++] = nums[i++];
        while(j <= r) tmp[pos++] = nums[j++];
        for(int i = l; i <= r; ++i) nums[i] = tmp[i];
    }

    void merge_sort(vector<int>& nums, vector<int>& tmp, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        merge_sort(nums, tmp, l, mid);
        merge_sort(nums, tmp, mid + 1, r);
        merge(nums, tmp, l, r);
    }

    // 堆排序：要实现最小到大，则维护大顶堆
    void init_heap(vector<int>& nums, int right){
        for(int i = nums.size() / 2; i >= 0; --i) adjust_heap(nums, right, i);
    }

    void adjust_heap(vector<int>& nums, int right, int idx){
        if(idx > right) return;
        int l = idx * 2 + 1,
            r = idx * 2 + 2,
            max_child = idx;
        max_child = (l <= right && nums[max_child] < nums[l]) ? l : max_child;
        max_child = (r <= right && nums[max_child] < nums[r]) ? r : max_child; 
        if(nums[idx] < nums[max_child]){
            swap(nums[idx], nums[max_child]);
            adjust_heap(nums, right, max_child);
        }
    }

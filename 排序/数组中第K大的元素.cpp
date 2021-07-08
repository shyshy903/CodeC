// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 示例 1:

// 输入: [3,2,1,5,6,4] 和 k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
// 输出: 4

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include <queue>

using namespace std;

int topK_quickSort(vector<int> &nums, int k, int l, int r){
    if (l>=r){
        return;
    }
    int base = nums[l];
    int i = l, j = r;
    while(i < j){
        while(nums[j] >= base && i < j){
            j--;
        }
        while(nums[i] <= base && i < j){
            i++;
        }
        if(i < j){
            swap(nums[i], nums[j]);
        }
    }
    nums[l] = nums[i];
    nums[i] = base; //将base与数据交换
    if (i == k-1){
        return nums[i];
    }else if (i < k-1)
    {
        topK_quickSort(nums, k, i+1, r);  // 右半部分
    }else{
        topK_quickSort(nums, k, l, i-1);  // 左半部分
    }
}


int topk_heapSort1(vector<int> &nums, int k){
    priority_queue<int> que;
    for(auto i : nums){
        que.push(i);
    }
    while(!que.empty){
        for(int i=0; i < k-1; i++){
            que.pop();
        }
        return que.top();
    }
    return;
}

// 建堆，调整，删除


void make_maxheap(vector<int> &nums, int size){
    int n = nums.size()/2;
    for(int i = n; i > 0; i--){
        adjust(nums,i,size);
    }

}
void adjust(vector<int> &nums, int i, int size){
    int l = i*2 + 1, int r = i*2 + 2;
    int large = i;
    if (l < size && a[l] > nums[large]){
        large = l;
    }
    if (r < size && a[r] > nums[large]){
        large = r;
    }
    if(large!=i){
        swap(nums[i], nums[large]);
        adjust(nums, large, size);
    }
}

int topk_heapSort2(vector<int> &nums, int k){
    int size = nums.size();
    make_maxheap(nums, size);
    for(int i = nums.size()-1; i < nums.size()-k+1; --i){
        swap(nums[0], nums[i]);
        --size;
        adjust(nums, 0, size);
    }
    return nums[0];
}

int main(){


}
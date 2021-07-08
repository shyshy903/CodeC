// 给你一个链表数组，每个链表都已经按升序排列。

// 请你将所有链表合并到一个升序链表中，返回合并后的链表。

//  

// 示例 1：

// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：链表数组如下：
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 将它们合并到一个有序链表中得到。
// 1->1->2->3->4->4->5->6

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//归并合并
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if (l1 == nullptr || l2 == nullptr) return l1 ? l1 : l2;
        ListNode head;
        ListNode* prev = &head;
        while(l1 && l2){
            if(l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1==nullptr? l2 : l1;
        return head.next;
    }
    
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l==r)  return lists[1];
        if(l > r) return nullptr;
        int mid = l + (l-r)/2;
        return mergeTwoLists(merge(lists,l,mid), merge(lists,mid+1,r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        merge(lists, 0, lists.size()-1);
    }
};

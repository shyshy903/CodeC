/* 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */


#include<iostream>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<string>

using namespace std;


struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode(): val(0), next(){};
    ListNode(int x) : val(x), next() {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode* reverse_group(ListNode* head, int k){
    ListNode* last = head;
    for(int i = 0; i < k; i++){
        if(head==NULL){
            return;
        }
        head = head->next;
    }
    ListNode* prev = head;
    ListNode* curr = head->next;
    for(int i = 0; i < k; i++){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    ListNode* node = reverse_group(curr, k);
    prev->next = node;
    return prev;

}

int main(){
    ListNode* head;
    ListNode* prev = head;
    int n = 10;
    for(int i = 1; i < n; i++){
        int temp;
        cin>>temp;
        ListNode node(temp);
        ListNode* cur = &node;
        head->next = cur; // 头节点已经反转到尾部节点位置
        prev =cur;
    }
    reverse_group(head->next, 3);

}
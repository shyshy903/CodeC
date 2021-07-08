/* 编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-list */s


#include <unordered_map>
#include <iostream>

#define _GLIBCXX_UNORDERED_MAP 1

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
    unorderd_map<ListNode*, int> set;
    while(headA){
        set[headA]++;
        headA = headA->next;
    }
    while(headB){
        if(set[headB]){
            return headB;
        }
        headB = headB->next;
    }
    return -1;
}


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a != b)
        {
            a = a? a->next : headB;                 //为NULL时，将值置为另一个链表的起点
            b = b? b->next : headA; 
        }
        return a;
    }
};



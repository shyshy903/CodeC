/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        std::reverse(temp.begin(),temp.end());
        return temp;
    }
};


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(!head){
            return res;
       }
       printListFromTailToHead(head->next);
       res.push_back(head->val);
       return res;
    }
};

// 后续遍历


// 发转链表
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        vector<int> res;
        while(pre){
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* next = head->next;
        ListNode*  pre = NULL;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

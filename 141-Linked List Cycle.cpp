/*

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

*/
/*

一个每次前进两格，一个每次前进一格，如果有环，迟早会重合。不能一个移动，一个停着等相遇，可能停着的那个不在环里

*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner->next!=NULL && runner->next->next!=NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner) return true;
        }
        return false;
    }
};

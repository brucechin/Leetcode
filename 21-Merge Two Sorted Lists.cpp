/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/

/*

mergesort的思想，没啥好讲的，result记录新list的头，tmp作为iterator

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        ListNode * result = new ListNode(0);
        ListNode * tmp = result;
        while(l1 && l2){
            if(l1->val > l2->val){
                tmp->next = l2;
                l2 = l2->next;
            }else{
                tmp->next = l1;
                l1 = l1->next;
            }
            tmp = tmp->next;
        }
        while(l1){
            tmp->next = l1;
            l1 = l1->next;
            tmp = tmp->next;
        }
        while(l2){
            tmp->next = l2;
            l2 = l2->next;
            tmp = tmp->next;
        }
        return result->next;
    }
};

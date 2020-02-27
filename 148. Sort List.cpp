// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge( ListNode* head1 , ListNode * head2){
        ListNode* d = new ListNode (0);            // dummy node
        ListNode* e = d;
        while(head1||head2){
            if(head1 && (!head2 || head1->val <= head2 -> val) ){
                e=e->next= head1 ; 
                head1 = head1 -> next;
            }
            if(head2 && (!head1 || head2->val < head1 -> val) ){
                e=e->next= head2 ; 
                head2 = head2 -> next;
            }
        }
        e->next = NULL;
        return d->next;
    }
   ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast =head->next;
         while(fast && fast->next){         // to find middle node     
            fast= fast->next->next;
            slow = slow->next;
        }
        ListNode* headb = slow->next;     // headb is start of 2nd half of list
        slow->next = NULL;                 
        return merge(sortList(head) , sortList(headb));
        }
};
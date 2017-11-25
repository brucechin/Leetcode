/*

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7


*/

//相比string类型的大数加法，多加了个stack而已
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode* list = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()) {sum += s1.top();s1.pop();}
            if(!s2.empty()) {sum += s2.top();s2.pop();}
            list->val = sum % 10;
            ListNode* head = new ListNode(0);
            head -> next = list;
            list = head;
            sum = sum / 10;
        }
        list->val = sum;
        return list->val == 0 ? list->next : list;
    }
};
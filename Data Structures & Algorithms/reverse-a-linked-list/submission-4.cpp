class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next; // save next node

            curr->next = prev;           // reverse the link

            prev = curr;                 // move prev
            curr = next;                 // move curr
        }

        return prev;
    }
};
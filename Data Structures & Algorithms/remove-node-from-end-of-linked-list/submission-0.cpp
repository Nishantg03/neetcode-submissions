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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Find length
        int len = 0;
        ListNode* curr = head;

        while (curr != NULL) {
            len++;
            curr = curr->next;
        }

        // Node to remove is at index len - n
        int index = len - n;

        // If removing head
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            return head;
        }

        // Move to node before the one we want to remove
        curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        // curr->next is the node to remove
        ListNode* temp = curr->next;

        curr->next = temp->next;
        temp->next = NULL;

        return head;
    }
};
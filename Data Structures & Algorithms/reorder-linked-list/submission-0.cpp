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
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        // STEP 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Reverse the second half
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while (second != NULL) {
            ListNode* next = second->next;

            second->next = prev;

            prev = second;
            second = next;
        }

        // prev = head of reversed second half
        second = prev;

        // STEP 3: Merge both halves
        ListNode* first = head;

        while (second != NULL) {

            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};
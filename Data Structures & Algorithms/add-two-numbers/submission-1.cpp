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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* curr = &dummy;

        ListNode* p1 = l1;
        ListNode* p2 = l2;

        int carry = 0;

        while (p1 != NULL || p2 != NULL || carry != 0) {

            int sum = carry;

            if (p1 != NULL) {
                sum += p1->val;
                p1 = p1->next;
            }

            if (p2 != NULL) {
                sum += p2->val;
                p2 = p2->next;
            }

            // Current digit
            int digit = sum % 10;

            // Carry for next position
            carry = sum / 10;

            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        return dummy.next;
    }
};
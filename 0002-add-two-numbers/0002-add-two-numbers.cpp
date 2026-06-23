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
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* newNode = new ListNode(-1);
        ListNode* curr = newNode;
        int carry = 0;
        while (t1 != NULL || t2 != NULL) {
            int sum = carry;
            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->val;
                t2 = t2->next;
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
            if (carry) {
                ListNode* node = new ListNode(carry);
                curr->next = node;
            }
        }

        return newNode->next;
    }
};
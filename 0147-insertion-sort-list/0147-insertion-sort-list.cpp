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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head ;

        ListNode dummy(0) ; 
        dummy.next = head ; 

        ListNode* lastSorted = head ;
        ListNode* current = head->next ; 
        while(current){
            if(lastSorted->val <= current->val){
                lastSorted = current ; 
            }
            else {
                //find the insertion point 
                ListNode* prev = &dummy;

                while (prev->next->val < current->val) {
                    prev = prev->next;
                }

                // Remove current from its position
                lastSorted->next = current->next;

                // Insert current after prev
                current->next = prev->next;
                prev->next = current;
            }

            // Move to next node to process
            current = lastSorted->next;
        }

        return dummy.next;
        
    }
};
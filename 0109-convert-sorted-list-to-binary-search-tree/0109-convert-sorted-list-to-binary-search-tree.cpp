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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* curr;
    int getlength (ListNode* head){
        int len= 0 ;
        while(head){
            len ++ ; 
            head = head->next;
        }
        return len ; 
    }
    TreeNode* build (int left , int right){
        if(left > right) return NULL ;
        int mid = left + (right - left) / 2;

        TreeNode* leftchild = build (left , mid-1);

        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next ; 

        root->left = leftchild;
        root->right = build(mid+1 , right);

        return root ; 
    }

    TreeNode* sortedListToBST(ListNode* head) {
        curr = head ;
        int n = getlength(head);
        return build(0 , n-1);
    }
};
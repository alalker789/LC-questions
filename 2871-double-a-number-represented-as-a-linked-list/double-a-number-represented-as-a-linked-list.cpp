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
    ListNode* rev(ListNode* head){
        ListNode *prev = NULL, *curr = head;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = rev(head);

        ListNode* curr = head;
        int carry = 0;

        while(curr){
            int sum = 2*curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if(curr->next == NULL && carry){
                curr->next = new ListNode(0);
            }

            curr = curr->next;
        }

        return rev(head);
    }
};
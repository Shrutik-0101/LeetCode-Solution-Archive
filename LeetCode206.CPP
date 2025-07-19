/*
Trick:
Think of the process as “reversing arrows.”
As you traverse the list, redirect each node’s next pointer to its previous node.
By the end, the last node becomes the new head.

Notes to Remember:
Use two pointers: one for the current node, one for the reversed part.
Always store the next node before changing pointers.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = node;
            node = head;
            head = temp;
        }

        return node;        
    }
};
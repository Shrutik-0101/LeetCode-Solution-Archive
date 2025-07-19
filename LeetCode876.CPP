/*
Use two pointers—slow and fast.
Move slow by 1 node and fast by 2 nodes each step.
When fast reaches the end, slow will be at the middle.
This works because the fast pointer covers twice the distance.
So by the time it finishes, slow has covered half.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

/*
1. Find the Length of the List
Traverse the list once to calculate its length
Use a pointer (dummy) starting at head and move to the end
While doing so, keep track of the node count

Trick: You can’t rotate if you don’t know how long the list is — always find the length first

2. Reduce k with Modulo
If k ≥ length, rotation would just repeat
So use k % length to avoid unnecessary work

Trick: Rotating a full cycle brings you back to the start — use modulo to skip full rotations

3. Edge Case: No Rotation Needed
If position == 0 after modulo, return head directly

Trick: If the rotation count is a multiple of the length, the list remains unchanged

4. Find the New Tail
New head will be at position length - k
Traverse again to reach the node before that
Mark this as the new tail and break the list there

Trick: The node just before the new head becomes the new tail — cut the list at that point

5. Reconnect List
Original tail (dummy) now points to old head
This links the rotated part to the beginning

Trick: Turn the list into a circular list temporarily, then cut at the right point
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int length = 1;
        ListNode* dummy = head;

        while (dummy->next) {
            dummy = dummy->next;
            length++;
        }

        int position = k % length;
        if (position == 0) return head;

        ListNode* current = head;
        for (int i = 0; i < length - position - 1; ++i) {
            current = current->next;
        }

        ListNode* newHead = current->next;
        current->next = nullptr;
        dummy->next = head;

        return newHead;        
    }
};
/*
1. Use a Dummy Head
Create a dummy node to simplify the construction of the result list
Helps avoid handling special cases for the first node

Trick: Use a dummy node as a placeholder for the head of the resulting list

2. Traverse Both Lists Simultaneously
Loop continues while l1, l2, or a non-zero carry exists
Use conditional (l1 ? l1->val : 0) to handle unequal list lengths

Trick: Always treat missing digits as zero when one list is shorter

3. Handle the Carry
Add corresponding digits from both lists and the carry
Update carry as sum / 10
Store the current digit as sum % 10

Trick: Just like manual addition — add digits, store remainder, carry the rest

4. Advance Pointers Safely
Move to the next node in each list only if it exists

Trick: Use ternary (l1 ? l1->next : nullptr) to prevent null pointer errors

5. Clean-Up and Return
Result starts from dummyHead->next, not dummyHead itself
Delete the dummy node to free memory

Trick: Result is the list after the dummy node; clean up memory if using new
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        return result;
    }
};
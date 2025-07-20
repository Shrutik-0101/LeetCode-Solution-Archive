/*
Finding the Middle (getmid)
Use two pointers: slow and fast
slow moves one step, fast moves two
When fast reaches the end, slow is at the middle
Start fast at head->next to make slow land on the node before the true middle — helps with splitting

Trick: Think "tortoise and hare" race — the slow pointer always marks the mid when the fast finishes

2. Splitting the List (sortList)
Base case: If the list has 0 or 1 node, it's already sorted
Use getmid to divide the list into two halves
Break the list at the mid by setting mid->next = NULL

Trick: Always cut the list into two parts before any recursive call to sort

3. Recursive Sorting (sortList)
Recursively sort both halves
The problem is reduced to smaller subproblems (divide and conquer)

Trick: Just like merge sort on arrays, but cutting the list instead of using indices

4. Merging Two Sorted Lists (merge)
Use a dummy node to simplify list building
Compare node values from both lists and attach the smaller one to the merged list
When one list is exhausted, attach the remaining part of the other

Trick: Think of dummy as a temporary head — it helps avoid special cases for the first node

5. Final Assembly
After both halves are sorted, merge them
Return the head of the merged list (i.e., dummy->next)

Trick: Always build from dummy and return dummy->next to get the actual sorted list
*/

class Solution {
public:
    ListNode* getmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        dummy = dummy->next;
        return dummy;
    }

    ListNode* sortList(ListNode* head) {
        // using merge sort

        // base case
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mid = getmid(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* result = merge(left, right);

        return result;
    }
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Count nodes
        ListNode* temp = head;
        int count = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            count++;
        }

        // Step 2: Make list circular
        temp->next = head;

        // Step 3: Find the new tail (at count - k % count - 1)
        k = k % count;
        if (k == 0) {
            temp->next = nullptr; // break circular link
            return head;
        }

        int stepsToNewTail = count - k;
        ListNode* newTail = head;
        while (--stepsToNewTail) {
            newTail = newTail->next;
        }

        // Step 4: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

class Solution {
public:
    void printlist(ListNode* head){
        while(head!=nullptr){
            cout<<head->val<<" ";
            head=head->next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Count total nodes
        ListNode* tail = head;
        int n = 0;
        while(tail != nullptr){
            n++;
            tail = tail->next;
        }

        int g = n / k;  // number of complete groups to reverse

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        ListNode* prevGroupEnd = nullptr;
        ListNode* newHead = nullptr;

        while(g > 0){
            int c = 0;

            // Store the start of current group (will become end after reversal)
            ListNode* groupStart = curr;

            // Reverse k nodes
            prev = nullptr;
            while(c < k){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                c++;
            }

            // Set new head if it's the first group
            if(newHead == nullptr){
                newHead = prev;
            }

            // Connect previous group to current reversed group
            if(prevGroupEnd != nullptr){
                prevGroupEnd->next = prev;
            }

            // Update prevGroupEnd to current group's end
            prevGroupEnd = groupStart;

            g--;
        }

        // Attach the remaining nodes
        if(prevGroupEnd != nullptr){
            prevGroupEnd->next = curr;
        }

        return newHead;
    }
};

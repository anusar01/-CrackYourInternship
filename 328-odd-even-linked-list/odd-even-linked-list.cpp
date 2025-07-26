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
    ListNode* oddEvenList(ListNode* head) {
        //make another linked list
        if (!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        ListNode* l2=dummy;
        ListNode* curr=head;
        while(curr && curr->next){
            l2->next=curr->next;
            l2=l2->next;
            curr->next=curr->next->next;
            if (curr->next) curr = curr->next;
            else break;
        }
        l2->next=nullptr;
        curr->next=dummy->next;
        return head;
    }
};
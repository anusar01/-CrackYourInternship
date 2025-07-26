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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next=nullptr;
        //from where the slow pointer is reverse
        ListNode* curr=second;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        //prev is the head;
        ListNode* l1=head;
        while(prev!=nullptr){
            ListNode* l1next=l1->next;
            l1->next=prev;
            ListNode* prevnext=prev->next;
            prev->next=l1next;
            prev=prevnext;
            l1=l1next;
        }
    }
};
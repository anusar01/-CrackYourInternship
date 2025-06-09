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
    void printlist(ListNode* head){
        while(head!=nullptr){
            cout<<head->val<<" ";
            head=head->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        if (!head || !head->next) return true;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        //reverse nextNode
        ListNode* nextpt=nullptr;
        while(curr!=nullptr){
            nextpt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextpt;
        }
        ListNode* first = head;
        ListNode* second = prev; // Head of reversed half
        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
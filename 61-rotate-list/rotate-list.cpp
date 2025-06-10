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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        k=k%count;
        if (k == 0) return head;
        //move right
        int shift=count-k;
        ListNode* ptr=head;
        while(shift>1){
            ptr=ptr->next;
            shift--;
        }
        ListNode* nextptr=ptr->next;
        ptr->next=nullptr;
        ListNode* newhead=nextptr;
        while(nextptr->next!=nullptr){
            nextptr=nextptr->next;
        }
        nextptr->next=head;
        return newhead;    
    }
};
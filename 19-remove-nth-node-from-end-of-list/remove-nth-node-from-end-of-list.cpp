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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head;
        ListNode* cnt=head;
        
        //find count of list
        int c=0;
        while(cnt!=nullptr){
            c++;
            cnt=cnt->next;
        }
        if(n==c){
            return head->next;
        }
        for(int i=0;i<c-n-1;i++){
            ptr=ptr->next;
        }
        if(ptr->next!=nullptr){
        ptr->next=ptr->next->next;
        }
        else ptr->next=nullptr;
        return head;
    }
};
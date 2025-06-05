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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }

        if(list1->val>list2->val){
            swap(list1,list2);
        }
        ListNode* prev=nullptr;
        ListNode* head=list1;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                //move list1 to next
                prev=list1;
                list1=list1->next;
            }else{
                //add node with value of list2 before current list1
                ListNode* temp=list2->next;
                prev->next=list2;
                list2->next=list1;
                
                prev=list2;
                list2=temp;

            }
        }
        //now if any of list2 nodes are left then append
        //list1 is already added
        if(list2!=nullptr){
            prev->next=list2;
        }
        return head;
    }
};

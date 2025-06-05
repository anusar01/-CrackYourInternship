/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tailA=headA;
        ListNode* tailB=headB;
        int cntA=0,cntB=0;
        while(tailA->next!=nullptr){
            cntA++;
            tailA=tailA->next;
        }
        while(tailB->next!=nullptr){
            cntB++;
            tailB=tailB->next;
        }
        if(tailA->val!=tailB->val){
            return nullptr;
        }
        while(cntA>cntB){
            headA=headA->next;
            cntA--;
        }
        while(cntA<cntB){
            headB=headB->next;
            cntB--;
        }
        //now moveboth ptr together and compare
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
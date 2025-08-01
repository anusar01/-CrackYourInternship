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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //what iif we have k pointers
        //we have to point each ListNode*
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(auto list:lists){
            while(list!=nullptr){
                minHeap.push(list->val);
                list=list->next;
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(!minHeap.empty()){
            curr->next=new ListNode(minHeap.top());
            minHeap.pop();
            curr=curr->next;
        }
        return dummy->next;
    }
};
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
    ListNode* middleNode(ListNode* head) {
        ListNode* start;
        start=head;
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        int middle;
        if(count%2==0){
            middle=count/2+1;
        }else{
            middle=(count+1)/2;
        }
        for(int i=0;i<middle-1;i++){
            start=start->next;
        }
        return start;
    }
};
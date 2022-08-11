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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* nextptr=head;
        int count=0;
        
        while(nextptr!=nullptr&&count!=k){
            nextptr=nextptr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
            count++;
        }
        if(count!=k){
            curr=prev;
            while(nextptr!=head){
                prev=prev->next;
                curr->next=nextptr;
                nextptr=curr;
                curr=prev;
            }
            return head;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
    
};
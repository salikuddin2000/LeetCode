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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        
        ListNode *slow=head,*fast=head,*temp=NULL;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        
        return mergeList(l1,l2);
    }
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        ListNode *prev=new ListNode(0);
        ListNode *curr=prev;
        
        while(l1&&l2){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
            // cout<<curr->val;
        }
        if(l1) curr->next=l1;
        if(l2) curr->next=l2;
        
        return prev->next;
    }
};
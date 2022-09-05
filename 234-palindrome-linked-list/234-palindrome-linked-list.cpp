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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        vector<int> arr;
        arr.push_back(head->val);
        while(fast->next&&fast->next->next){
            slow=slow->next;
            arr.push_back(slow->val);
            fast=fast->next->next;
        }
        if(fast->next==NULL) arr.pop_back();
        while(slow->next){
            slow=slow->next;
            if(slow->val!=*(arr.end()-1))return false;
            arr.pop_back();
        }
        return true;
    }
};
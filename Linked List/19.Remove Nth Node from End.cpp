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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        struct ListNode* fast = head;
        struct ListNode* slow = head;
        struct ListNode* temp = head;
        
        while(fast && n--){
            fast = fast->next;
        }
        while(fast!=NULL and fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast!=NULL){
            slow->next = slow->next->next;
        }
        else{
            head = head->next;
        }
        return head;
    }
};

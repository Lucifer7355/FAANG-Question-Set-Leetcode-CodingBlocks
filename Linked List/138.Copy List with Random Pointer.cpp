/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        temp = head;
        Node* newHead = NULL;
        Node* newTail = NULL;
        while(temp!=NULL){
            Node* copy = temp->next;
            if(newHead == NULL){
                newHead = copy;
                newTail = copy;
                temp->next = copy->next;
                copy->next = NULL;
            }else{
                temp->next = copy->next;
                copy->next = NULL;
                newTail->next = copy;
                newTail = copy;
            }
            temp = temp->next;
        }
        return newHead;
    }
    
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head){
        if(head==NULL){
            return NULL;
        }
        Node* dummyHead = new Node(0,NULL,head,NULL);
        Node* current = dummyHead;
        Node* prev = dummyHead;
        stack<Node*> s;
        s.push(head);
        while(!s.empty()){
            current = s.top();
            s.pop();
            prev->next = current;
            current->prev = prev;
            if(current->next!=NULL){
                s.push(current->next);
            }
            if(current->child!=NULL){
                s.push(current->child);
                current->child = NULL;
            }
            prev = current;
        }
        dummyHead->next->prev = NULL;
        return dummyHead->next;
    }
};

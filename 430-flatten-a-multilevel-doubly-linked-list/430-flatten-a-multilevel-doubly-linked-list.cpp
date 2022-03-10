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
        helper(head);
        return head;
    }
    Node* helper(Node* head) {
        Node* prev=head , * cur=head;
        
        while(cur){
            if(cur->child){
                Node * nextNode=cur->next;//cur ke next node ko advance mei save kr lia
                Node * child_tail=helper(cur->child);//Im asking recursion function to bring me tail node of children list
                cout<<" child_tail is  "<<child_tail->val<<endl;
                cur->next=cur->child,
                cur->child->prev=cur,
                cur->child=NULL;
                child_tail->next=nextNode;
                if(nextNode) nextNode->prev=child_tail;
                prev=child_tail,
                cur=nextNode;
            }
            else{ //I'm not having child node
                prev=cur,
                cur=cur->next;
                    
            }
        }
        return prev;
    }
};
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
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        //Now you have atleast one node 
        Node   *temp=head;
        
        for(;temp;){
            Node* nextNode=temp->next;
            Node * newNode=new Node(temp->val);
            // cout<<newNode->val<<endl;
            temp->next=newNode,
            temp=temp->next;
            temp->next=nextNode;
            temp=temp->next;
            
        }
        //second step mei I'm assigning random pointers correspondoing to every node
        
        for(temp=head ;temp ;temp=temp->next->next){
            temp->next->random= !(temp->random) ? (NULL): temp->random->next ;
        }
        
        //I beleive until now everything is all good to go
        //Finally In third step I' m unwiring Deep copy from original one(s)
        
        Node*newHead=head->next;
        Node *prev=head,*curr=newHead ; 
        
        for(;1;){
            prev->next=curr->next,
            prev=curr->next;
            if(!prev) break;//yadi prev NULL ho gya 
            curr->next=prev->next,
            curr=prev->next;
        }
        // I think I'm done writing algo 
        // for(Node* chu=head;chu;chu=chu->next)cout<<chu->val <<" "; cout<<endl;
        // for(Node* chu=newHead;chu;chu=chu->next)cout<<chu->val <<" "; cout<<endl;
        return newHead;
        
    }
};
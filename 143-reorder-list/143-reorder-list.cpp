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
    /*
    1 2 3 4 5
    
    5 4 3 2 1
    
    intutions:
    I can sense that somehow mid node is involved in this problem
    How I can be too sure about this becoz mid is shifted to the last
    If two nodes are there then they are already reordered 
    
    */
    void reorderList(ListNode* head) {
        //If two or less than two nodes are there then they are already reordered 
        if(!head->next || !head->next->next){
            return ;
        }
        ListNode *midNode=head, *fast=head ,*prevNode=NULL;
        while(fast && fast->next){
            prevNode=midNode,
            midNode=midNode->next,
            fast=fast->next->next;
        }
        prevNode->next=NULL;//detacing from midNode on-wards
        stack< ListNode* > listStack;
        while(midNode){
            listStack.push(midNode),
            midNode=midNode->next;
        }
        // cout<<"prevNode<<endl; "<< prevNode->next<<endl;
        ListNode *curNode=head;
        while(curNode){
            // cout<<"val is "<<curNode->val<<" "<<curNode->next<<endl;
            ListNode *topNode=listStack.top(); listStack.pop();
             
            if(!curNode->next){
                curNode->next=new ListNode(topNode->val);
                curNode=curNode->next;
                 
                break;
            }
            ListNode *nextNode=curNode->next;
            curNode->next=topNode,
            curNode=curNode->next;
            
            curNode->next=nextNode;
            
            curNode=curNode->next;
            //  
            /*
            1 7 2 6 3 5 ||   4     
            
            
            1 4 2 3    ||  
            */ 
            
        }
        
        cout<<curNode->val<<endl;
        if(listStack.size()==1){
                curNode->next=new ListNode(listStack.top()->val);
                
            }
        
       // end of the findtionn 
    }
};
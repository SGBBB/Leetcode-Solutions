/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node* ,Node *> M;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;//base case
        Node* newNode=new Node(node->val);
        M[node] =newNode;
        queue<Node*> q;
        q.push(node);
        for(;!q.empty();){
            
            // for(int n=q.size();n--;){
                Node* front_node=q.front(); q.pop();
                     
                   for(auto i:front_node->neighbors){
                       if(!M.count(i)){M[i]=new Node(i->val);
                           q.push(i);
                           
                       }
                    M[front_node]->neighbors.push_back( M[i]);
                   }
                
            // }
        }
        cout<<M[node]->val;
        return M[node];
    }
};
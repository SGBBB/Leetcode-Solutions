struct Node{
    Node * arr[26];
    int flag=0;
};
Node * head=new Node();
class Solution {
    string ans="";
    void insert(string str){
        Node *temp=head;
        
        for(char ch:str){
            int idx=ch-'a';
            if(!temp->arr[idx]){
                temp->arr[idx]=new Node();
            }
            temp=temp->arr[idx];
        }
        temp->flag=1;
    }
    string find(string str){
        string ans="";
        Node *temp=head; 
        int n=str.size();
        int i=0;
        
        for(;i<n and !temp->flag and temp->arr[str[i]-'a'];temp=temp->arr[str[i]-'a'] ,i++){
            
            ans+=str[i] ;
            
            cout<<ans<<endl;
        }
        
        if(temp->flag) return ans;
        return str;
    }
public:
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        head=new Node();
        for(string word:dictionary){
            insert(word);
        }
        stringstream ss(sentence);
        string str;
        while(ss>>str){
            string res=find(str);
            
            ans+=res+" ";
        }
        ans.pop_back();
        
        return ans;
    }
};
struct Node{
    Node* arr[26];
    bool flag=0;
};
Node* root=new Node();
class WordDictionary {
public:
    
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* temp=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!temp->arr[idx] ){
                temp->arr[idx]=new Node();
            }
            temp=temp->arr[idx];
        }
        temp->flag=true;
    }
    
    bool search(string word,int idx=0 ,Node* temp=root) {
        int len=word.size();
        if(!temp) return 0;
        if(idx<len){
            
            
            if(word[idx]=='.' ) {
            for(char i=0;i<=25;i++) {
                if(!temp->arr[i]) continue;
                if(search(word,idx+1,temp->arr[i])) return 1;
                }
            return false;
            }
            else return search(word,idx+1,temp->arr[word[idx]-'a'] );
        }
        
        return idx==len and temp->flag;//this situation will occur when our idx==length of word
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
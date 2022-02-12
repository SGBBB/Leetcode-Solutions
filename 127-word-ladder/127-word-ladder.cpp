class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end() );
        queue<string> q;
        q.push(beginWord);
        int changes=1;
        for(;!q.empty();changes++){
            int len=q.size();
            for(;len--;){
                string top=q.front();
                q.pop();
                if(top==endWord) return changes;
                s.erase(top);//while processing visited mark krne se sahi h ki usko delete krlo
                
            for(char &ch:top){
                char temp=ch;
                for(char c='a';c<='z';c++ ){
                    ch=c;
                    if(s.count(top)) q.push(top);
                }
                ch=temp;
            }  
                
            }
            
        }
        return 0;
    }
};
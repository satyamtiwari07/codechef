class Trie{
    public:
    Trie *children[27];
    bool isend;
    Trie(){
        isend=false;
        for(int x=0;x<=26;x++){
            children[x]=NULL;
        }
    }
};

class WordDictionary {
   Trie *root;
public:
    WordDictionary() {
         root=new Trie();
    }
    
    void addWord(string word) {
        
        Trie *temp=root;

        for(int x=0;x<word.size();x++){
            int idx=word[x]-'a';
            if(temp->children[idx]==NULL){
                temp->children[idx]=new Trie();
            }
            temp=temp->children[idx];
        }
        temp->isend=true;
    }

    bool searchhelper(Trie *temp,string &word,int idx){
        if(temp==NULL) return false;
        if(idx==word.size()) 
           return temp->isend;
        
        if(word[idx]=='.'){
            //search all 26 charcters
            for(int x=0;x<26;x++){
                if(searchhelper(temp->children[x],word,idx+1))
                  return true;
            }
        }
        else
        return searchhelper(temp->children[word[idx]-'a'],word,idx+1);
        return false;
    }
    
    bool search(string word) {
        Trie *temp=root;
         return searchhelper(temp,word,0);
        // return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

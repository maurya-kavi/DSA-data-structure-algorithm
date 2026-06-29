class WordDictionary {
public:
    
    struct trieNode{
        bool isEndOfWord;
        trieNode*children[26];
    };

    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        newNode->isEndOfWord=false;
        for(int i=0; i<26; i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }

trieNode*root;
    WordDictionary() {
        root=getNode();
    }
    
    void addWord(string word) {
        trieNode*crawler=root;
        for(char ch:word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode();
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->isEndOfWord=true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

private:
    bool searchHelper(const string& word, int index, trieNode* crawler) {
        if (index == word.length()) {
            return crawler->isEndOfWord;
        }
        
        char ch = word[index];
        
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (crawler->children[i] != NULL) {
                    if (searchHelper(word, index + 1, crawler->children[i])) {
                        return true;
                    }
                }
            }
            return false; 
        } else {
            if (crawler->children[ch - 'a'] == NULL) {
                return false;
            }
            return searchHelper(word, index + 1, crawler->children[ch - 'a']);
        }
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
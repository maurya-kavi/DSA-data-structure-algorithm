class Solution {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode*children[26];
    };

    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        for(int i=0; i<26; i++){
            newNode->children[i]=NULL;
        }
        newNode->isEndOfWord=false;
        return newNode;
    }

    void insert(trieNode*root,string &word,int &i){
        trieNode*crawler=root;
        int n=word.size();
        for(int i=0; i<n; i++){
            int idx=word[i]-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isEndOfWord=true;
    }

    string findWord(trieNode*root, string &s){
        trieNode*crawler=root;
        int n=s.size();
        string str="";
        for(int i=0; i<n; i++){
            str+=s[i];
            int idx=s[i]-'a';
            if(crawler->children[idx]==NULL){
                return "{";
            }
            crawler=crawler->children[idx];
            if(crawler->isEndOfWord==true){
                return str;
            }
        }
        return "{";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n=dictionary.size();
        trieNode*root=getNode();
        for(int i=0; i<n; i++){
            string word=dictionary[i];
            insert(root,word,i);
        }

        string result="";
        int m=sentence.size();
        string s="";
        for(int i=0; i<m; i++){
            if(sentence[i]==' ' || i==m-1){
                if(i==m-1) s+=sentence[i];
                string str=findWord(root,s);
                if(str=="{") {
                    if(!result.empty()) result+=" ";
                    result+=s;
                }else{
                    if(!result.empty()) result+=" ";
                    result+=str;
                }
                s="";
            }else{
                s+=sentence[i];
            }
        }
        return result;
    }
};
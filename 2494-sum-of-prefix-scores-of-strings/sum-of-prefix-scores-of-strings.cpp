class Solution {
public:
    struct trieNode{
        int freq;
        trieNode*children[26];
    };
    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        newNode->freq=0;
        for(int i=0; i<26; i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insert(trieNode*root, string&word){
        trieNode*crawler=root;
        for(auto &ch:word){
            int ind=ch-'a';
            if(crawler->children[ind]==NULL){
                crawler->children[ind]=getNode();
            }
            crawler=crawler->children[ind];
            crawler->freq++;
        }
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        trieNode*root=getNode();
        for(auto &word:words){
            insert(root,word);
        }

        vector<int>result(n);

        for(int i=0; i<n; i++){
            string word=words[i];
            // string str="";
            trieNode*crawler=root;
            int totfreq=0;
            for(auto &ch:word){
                // str+=ch;
                // now search for the str and find its freq as the prefix
                int ind=ch-'a';
                if(crawler->children[ind]==NULL){
                    break;
                }
                crawler=crawler->children[ind];
                int fre=crawler->freq;
                totfreq+=fre;
            }
            result[i]=totfreq;
        }
        return result;
    }
};










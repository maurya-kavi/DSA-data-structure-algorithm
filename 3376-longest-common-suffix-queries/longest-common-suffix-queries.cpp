class Solution {
public:
    struct trieNode{
        map<int,trieNode*>mp;
        int ind;
        int sz;
    };
    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        newNode->mp.clear(); // this is not neccessary as the mp is already empty
        newNode->ind=-1;
        newNode->sz=INT_MAX;
        return newNode;
    }
    //building the subtree for a word
    void insert(trieNode*root, string &word, int &i){
        int x=word.size();
        trieNode*crawler=root;
        for(auto &ch:word){
            int idx=ch-'a';
            if(!crawler->mp.count(idx)){
                crawler->mp[idx]=getNode();
            }
            crawler=crawler->mp[idx];
            int index=crawler->sz;
            if(index==INT_MAX){
                crawler->ind=i;
                crawler->sz=x;
            }else{
                if(crawler->sz > x){
                    crawler->sz=x;
                    crawler->ind=i;
                }
            }
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int smallestszstr=INT_MAX;
        int smallestszstrInd=-1;
        trieNode*root=getNode();
        int i=0;
        for(auto &word:wordsContainer){
            int szz=word.size();
            if(szz<smallestszstr) {
                smallestszstr=szz;
                smallestszstrInd=i;
            }
            reverse(word.begin(),word.end());
            insert(root,word,i);
            i++;
        }

        vector<int>result;
        for(auto &s:wordsQuery){
            reverse(s.begin(),s.end());
            trieNode*crawler=root;
            bool flag=true;
            for(char &ch:s){
                int idx=ch-'a';
                if(!crawler->mp.count(idx)){
                    flag=false;
                    if(crawler->sz==INT_MAX){ //  means crawler is at the top (root)
                        result.push_back(smallestszstrInd);
                        break;
                    }else{
                        int index=crawler->ind;
                        result.push_back(index);
                        break;
                    }
                }
                crawler=crawler->mp[idx];
            }
            if(flag){
                int index=crawler->ind;
                result.push_back(index);
            }
        }
        return result;
    }
};







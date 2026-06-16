class Solution {
public:
    struct trieNode{
        unordered_map<int,pair<int,trieNode*>>mp;
    };
    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        return newNode;
    }
    void insert(trieNode*root, string&word){
        trieNode*crawler=root;
        for(auto &ch:word){
            int ind=ch-'a';
            if(!crawler->mp.count(ind)){
                crawler->mp[ind].second=getNode();
            }
            crawler->mp[ind].first++;
            crawler=crawler->mp[ind].second;
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
            trieNode*crawler=root;
            int totfreq=0;
            for(auto &ch:word){
                int ind=ch-'a';
                if(!crawler->mp.count(ind)){
                    break;
                }
                int fre=crawler->mp[ind].first;
                totfreq+=fre;
                crawler=crawler->mp[ind].second;
            }
            result[i]=totfreq;
        }
        return result;
    }
};










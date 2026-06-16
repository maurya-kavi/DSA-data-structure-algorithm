class Solution {
public:
    struct trieNode{
        trieNode*children[10];
    };
    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        for(int i=0; i<10; i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }

    void insert(trieNode*root, string &str){
        trieNode*crawler=root;
        for(int i=0; i<str.size(); i++){
            int ind=str[i]-'0';
            if(crawler->children[ind]==NULL){
                crawler->children[ind]=getNode();
            }
            crawler=crawler->children[ind];
        }
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(), m=arr2.size();
        trieNode*root=getNode();
        for(int i=0; i<n; i++){
            int num=arr1[i];
            string str=to_string(num);
            insert(root,str);
        }
        int mxResult=0;
        for(int i=0; i<m; i++){
            int num=arr2[i];
            string s=to_string(num);
            trieNode*crawler=root;
            bool flag=true;
            for(int j=0; j<s.size(); j++){
                int ind=s[j]-'0';
                if(crawler->children[ind]==NULL){
                    mxResult=max(mxResult,j);
                    flag=false;
                    break;
                }
                crawler=crawler->children[ind];
            }
            // if all digits matched in the tree
            int sz=s.size();
            if(flag) mxResult=max(mxResult,sz);
        }
        return mxResult;
    }
};
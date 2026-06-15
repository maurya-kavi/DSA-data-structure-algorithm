class Solution {
public:
    struct trieNode{
        int val;
        trieNode*left;
        trieNode*right;
    };
    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        newNode->val=0;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }
    void insert(trieNode*root,int num){
        trieNode*crawler=root;
        for(int i=31; i>=0; i--){
            if((num>>i)&1){
                if(crawler->right==NULL){
                    crawler->right= getNode();
                    crawler->right->val=1;
                }
                crawler=crawler->right;
            }else{
                if(crawler->left==NULL){
                    crawler->left= getNode();
                    crawler->left->val=0;
                }
                crawler=crawler->left;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        trieNode*root=new trieNode();
        for(int &num:nums){
            insert(root,num);
        }

        // in the tree from top to down , we have keep the most significant bit in the top and least significant bit in the down

        // for the ideal condition to obtain the maximum xor , any ith bit should be 1 for one for the num and 0 for the another num

        int mxXor=0;
        for(int num:nums){
            trieNode*crawler=root;
            int val=0;
            for(int i=31; i>=0; i--){
                if((num>>i)&1){
                    // ith bit is 1, look for the node with 0 val ( means look for the left node) in the tree
                    if(crawler->left!=NULL){
                        val+=pow(2,i);
                        crawler=crawler->left;
                        continue;
                    }
                    crawler=crawler->right;
                }
                else{
                    if(crawler->right!=NULL){
                        val+=pow(2,i);
                        crawler=crawler->right;
                        continue;
                    }
                    crawler=crawler->left;
                }
            }
            mxXor=max(mxXor,val);
        }
        return mxXor;
    }
};
















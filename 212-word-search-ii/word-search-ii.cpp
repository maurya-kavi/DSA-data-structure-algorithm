class Solution {
public:

vector<string>result;
int n,m;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

    struct trieNode{
        bool endofword;
        trieNode*children[26];
        string word="";
    };

    trieNode*getNode(){
        trieNode*temp=new trieNode();
        temp->endofword=false;
        for(int i=0; i<26; i++){
            temp->children[i]=NULL;
        }
        temp->word="";
        return temp;
    }

    void insert(trieNode*root,string &str){
        trieNode*curr=root;
        for(char ch:str){
            if(curr->children[ch-'a']==NULL){
                // then create node
                curr->children[ch-'a']=getNode();
            }
            curr=curr->children[ch-'a'];
        }
        //at last we have constructed a subtree that consist of word
        curr->endofword=true;
        curr->word=str;
    }

    void dfs(vector<vector<char>>&board, int i, int j, trieNode*root){
        // if(root->children[board[i][j]-'a']==NULL) return ;
        root=root->children[board[i][j]-'a'];
        if(root->endofword==true) {
            result.push_back(root->word);
            root->endofword=false;
        }
        char ch=board[i][j];
        board[i][j]='$';
        for(int k=0; k<4; k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr<n && nr>=0 && nc<m && nc>=0 && board[nr][nc]!='$'&&
            root->children[board[nr][nc]-'a']!=NULL){
                dfs(board,nr,nc,root);
            }
        }
        board[i][j]=ch;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();

        trieNode*root=new trieNode();
        for(auto &str:words){
            insert(root,str);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    dfs(board,i,j,root);
                }
            }
        }

        return result;
    }
};
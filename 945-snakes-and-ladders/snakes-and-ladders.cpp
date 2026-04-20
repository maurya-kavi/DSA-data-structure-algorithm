class Solution {
public:
    pair<int,int> getCoord(int val,int n){
        int RT=(val-1)/n; //row from top
        int RB=(n-1)-RT; // row from bottom
        int col=(val-1)%n;

        if((n&1 && RB&1) || (n%2==0 && RB%2==0)) {
            // obtained col is ffrom right to left , so to make t left to right
            col=(n-1)-col;
        }

        return make_pair(RB,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        
        vector<vector<int>>vis(n, vector<int>(n,false));
        queue<int>q;
        vis[n-1][0]=true;
        int steps=0;
        q.push(1);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int x=q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int k=1;  k<=6; k++){
                    int val=x+k;
                    if(x+k >n*n) break;
                    pair<int,int>coord=getCoord(val,n);
                    int r=coord.first;
                    int c=coord.second;
                    if(vis[r][c]) continue;
                    vis[r][c]=true;
                    if(board[r][c]==-1) {
                        q.push(val);
                    }else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
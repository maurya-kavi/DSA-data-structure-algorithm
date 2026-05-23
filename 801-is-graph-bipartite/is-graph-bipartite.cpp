class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //using BFS
        //two coloring method 0 & 1
        int v=graph.size();
        vector<int>color(v,-1);
        queue<int>q;
        for(int i=0; i<v; i++){
            // for discontineous graph
            if(color[i]==-1){
            q.push(i);
            color[i]=0;
            }

            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int j=0; j<graph[node].size(); j++){
                    if(color[graph[node][j]]==-1){
                    q.push(graph[node][j]);
                    color[graph[node][j]] = (color[node]+1)%2;
                    }
                    else{
                        if(color[node]==color[graph[node][j]]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        //reverse node dir and apply topo sort

        vector<vector<int>>adjRev(graph.size());
        vector<int>indeg(graph.size(),0);

        for(int i=0; i<graph.size(); i++){
            for(auto & it: graph[i]){
                //reversing the direction
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int>q;
        for(int i=0; i<indeg.size(); i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int j=0; j<adjRev[node].size(); j++){
                indeg[adjRev[node][j]]--;
                if(indeg[adjRev[node][j]]==0){
                    q.push(adjRev[node][j]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
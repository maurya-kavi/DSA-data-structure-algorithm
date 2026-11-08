class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        // find ultimate parent
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        //connect node u and v
        int parU=findUPar(u);
        int parV=findUPar(v);
        if(parU==parV) return ;
        if(size[parU]>=size[parV]){
            parent[parV]=parU;
            size[parU]+=size[parV];
        }else{
            parent[parU]=parV;
            size[parV]+=size[parU];
        }
    }
    

};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU dsu(n);
        vector<vector<int>>edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);

                edges.push_back({dis,i,j});    
            }
        }
        
        // in krushkal algo->sorting is required to do
        sort(edges.begin(),edges.end()); // priority given to wt or dis
int ans=0;// weight of mst
        // traverse in the edges and connect if not connected
        int cntEdges=0; // a little bit of more optimization so we don't have to traverse to complete edges if we have already found the n-1 edges connecting all the nodes
        for(int i=0; i<edges.size(); i++){
            auto arr=edges[i];
            int wt=arr[0];
            int u=arr[1];
            int v=arr[2];
            // lets connect node u and v if not connected
            int parU=dsu.findUPar(u);
            int parV=dsu.findUPar(v);
            if(parU==parV) continue;
            else{
                ans+=wt;
                dsu.unionBySize(u,v);
                cntEdges++;
            }
            if(cntEdges==n-1) break;
        }
return ans;

        
    }
};


















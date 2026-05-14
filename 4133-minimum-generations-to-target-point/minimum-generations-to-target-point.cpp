class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int n=points.size();
        set<vector<int>>allPoints;
        int generation=0;
        for(int i=0; i<n; i++){
            if(points[i]==target) return generation;
            allPoints.insert(points[i]);
        }
        generation++;
        if(n<2) return -1;
        while(true){
            vector<vector<int>>curr(allPoints.begin(),allPoints.end());
            vector<vector<int>>newlyvector;

            for(int i=0; i<curr.size()-1; i++){
                for(int j=i+1; j<curr.size(); j++){
                    int a=(curr[i][0] + curr[j][0])/2;
                    int b=(curr[i][1] + curr[j][1])/2;
                    int c=(curr[i][2] + curr[j][2])/2;

                    vector<int>C={a,b,c};

                    if(!allPoints.count(C)){
                        if(C==target) return generation;
                        newlyvector.push_back(C);
                    }
                }
            }

            if(newlyvector.empty()) break;

            //if not empty then push all these element into the points vector
            for(auto v:newlyvector){
                allPoints.insert(v);
            }
            generation++;
        }
        return -1;
    }
};
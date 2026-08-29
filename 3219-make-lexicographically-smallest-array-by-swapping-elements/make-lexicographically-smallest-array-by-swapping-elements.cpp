class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>v=nums;
        int n=nums.size();
        sort(v.begin(), v.end());

        int groupNum=0;
        unordered_map<int,int>numToGroup; // kon si element kis group mein belong karega

        numToGroup[v[0]]=groupNum; // first element in the group number 0

        unordered_map<int,list<int>>groupToList; // in any group -> kon kon se element hain
        // list is implemented using doubly linked list that provide the 0(1) TC to access pop/push in the begining or pop/push in the end

        groupToList[groupNum].push_back(v[0]);

        for(int i=1; i<n; i++){
            if(abs(v[i]-v[i-1])>limit){
                groupNum++;

            }

            numToGroup[v[i]]=groupNum;
            groupToList[groupNum].push_back(v[i]);
        }

        vector<int>res(n);
        for(int i=0; i<n; i++){
            int num=nums[i];
            int group=numToGroup[num];
            res[i]=*groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return res;
    }
};
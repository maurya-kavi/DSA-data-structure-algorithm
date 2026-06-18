class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n=skills.size();
        if(k>=n){
            auto i= max_element(skills.begin(),skills.end())-skills.begin();
            return (int)i;
        }
        deque<int>dq;
        for(int num:skills) dq.push_back(num);
        bool flag=true;
        int cnt=0;
        int winSkill=-1;
        while(flag){
            int f=dq.front();
            dq.pop_front();
            int s=dq.front();
            dq.pop_front();

            int mx=max(f,s);
            int mn=min(f,s);

            dq.push_back(mn);
            dq.push_front(mx);

            if(mx==winSkill){
                cnt++;
            }else {
                cnt=1;
                winSkill=mx;
            }
            if(cnt==k){
                flag=false;
            }
        }
        for(int i=0; i<skills.size(); i++){
            if(skills[i]==winSkill) return i;
        }
        return -1;
    }
};
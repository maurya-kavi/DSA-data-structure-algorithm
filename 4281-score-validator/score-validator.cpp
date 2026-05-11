class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n=events.size();
        int score=0, cnt=0;
        for(int i=0; i<n && cnt<10; i++){
            if(events[i]=="0" || events[i]=="1" || events[i]=="2" || events[i]=="3" || events[i]=="4" || events[i]=="6") score+=stoi(events[i]);
            else if(events[i]=="W") cnt++;
            else if(events[i]=="WD" || events[i]=="NB") score++;
        }
        return {score,cnt};
    }
};
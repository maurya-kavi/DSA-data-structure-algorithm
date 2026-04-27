class Twitter {
public:
    int time = 0;
    
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, set<int>> followees;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        
        // max heap: {time, tweetId, userId, index}
        priority_queue<tuple<int,int,int,int>> pq;
        
        // include self
        followees[userId].insert(userId);
        
        // push latest tweet of each user
        for(int user : followees[userId]) {
            if(tweets[user].size() > 0) {
                int idx = tweets[user].size() - 1;
                auto [t, id] = tweets[user][idx];
                pq.push({t, id, user, idx});
            }
        }
        
        while(!pq.empty() && ans.size() < 10) {
            auto [t, id, user, idx] = pq.top();
            pq.pop();
            
            ans.push_back(id);
            
            if(idx > 0) {
                auto [nt, nid] = tweets[user][idx - 1];
                pq.push({nt, nid, user, idx - 1});
            }
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
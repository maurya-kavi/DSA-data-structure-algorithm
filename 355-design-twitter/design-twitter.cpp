class Twitter {
public:
    vector<pair<int,int>>feed;
    // unordered_map<int,vector<int>>mp; // for postTwwet
    unordered_map<int,set<int>>followunfollowmp;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed.push_back({userId,tweetId});
        // mp[userId].push_back(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        //user ka khud ka post or jisko follow kiya hai wo rahega
        set<int>s=followunfollowmp[userId];
        vector<int>ans;
        int cnt=0;
        int sz=feed.size();
        for(int i=sz-1; i>=0; i--){
            auto [f,se]=feed[i];
            if(f==userId){
                cnt++;
                ans.push_back(se);
                if(cnt==10) break;
                continue;
            }
            if(!s.count(f)) continue;
            cnt++;
            ans.push_back(se);
            if(cnt==10) break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        followunfollowmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followunfollowmp[followerId].erase(followeeId);
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
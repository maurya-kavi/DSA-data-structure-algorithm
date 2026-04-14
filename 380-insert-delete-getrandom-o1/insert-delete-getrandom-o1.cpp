class RandomizedSet {
public:
vector<int>nums;
unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val]=nums.size(); // val at ind 
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        //lekin agar val h
        int lastelement=nums.back();
        //find the ind of the val that we have to remove
        int ind=mp[val];

        nums[ind]=lastelement;
        mp[lastelement]=ind; // map mein bhi last wala element ka index update kardo
        nums.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class LRUCache {
public:
// first approach:lets implement it using a queue and a stack 
// now lets optimise it using doubly linked list 
int n;
list<int>dll; //key // list ds in c++ to implment doubly linked list
map<int,pair<list<int>::iterator,int>>mp;  // {key,{address,value}}
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makeRecentlyUsed(int key){
        //delete the previous from dll list then push it in the front
        //erase the address from the list
        dll.erase(mp[key].first);

        dll.push_front(key);
        //in the map update its address
        mp[key].first=dll.begin(); // mp[key].first = address

    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        // isko mostrecentlyused bana do means push it in the front of dll , then return the mp[key]
        makeRecentlyUsed(key);

        return mp[key].second; //return the value

    }
    
    void put(int key, int value) {
        
        if(mp.find(key)==mp.end()){
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }else{
            //update value in map and makeit recently used
            mp[key].second=value;
            makeRecentlyUsed(key);
        }
        if(n<0){
            //remove from the dll from the back
            int key_tobe_del=dll.back();
            dll.pop_back();
            mp.erase(key_tobe_del);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
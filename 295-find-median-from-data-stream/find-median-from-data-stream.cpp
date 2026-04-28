class MedianFinder {
public:
// we will maintain two pq left ad right 
// all the element of left will be less than the element in the right
//we will take max heap for left so we can move the largest element from the left to the right
// and min heap for the right so we can move smallest element from the right to the left
priority_queue<int>left; // max-heap
priority_queue<int,vector<int>,greater<int>>right; // min-heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // the numm we are getting to add are not coming  in the sorted order 
        // so first push it into the left then take the larget from left and then push into the right
        // and then if left size is less then move one lement fro right to left
        left.push(num);

        right.push(left.top());
        left.pop();

        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()) return left.top();
        return (left.top() + right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
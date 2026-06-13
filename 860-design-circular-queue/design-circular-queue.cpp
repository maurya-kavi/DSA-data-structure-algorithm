class MyCircularQueue {
public:
    vector<int>q;
    int head;
    int capacity;
    int count;
    MyCircularQueue(int k) {
        capacity=k;
        q.assign(k,0);
        count=0;
        head=0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        int next_idx=(count+head)%capacity;
        q[next_idx]=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        head = (head + 1) % capacity;
        count--;
        
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        
        // Calculate the position of the last inserted element
        int rear_idx = (head + count - 1) % capacity;
        return q[rear_idx];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
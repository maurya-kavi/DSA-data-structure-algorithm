class FooBar {
private:
    int n;
    binary_semaphore fooSem{1}; // starts unlocked so foo runs first
    binary_semaphore barSem{0}; // starts locked so bar waits


public:

//solve it using binary semaphore
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            fooSem.acquire(); //wait for foo's turn
        	// printFoo() outputs "foo". Do not change or remove this line.

        	printFoo();
            barSem.release(); //signal bar to run
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            barSem.acquire(); //wait for bar's turn
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooSem.release(); // Signal foo for the next iteration
        }
    }
};

// acquire() -> Value 1 se 0 karta hai (agar 0 hai toh wait karta hai)
// release() -> value 0 se 1 karta hai ( aur waiting thread ko jagata hai)

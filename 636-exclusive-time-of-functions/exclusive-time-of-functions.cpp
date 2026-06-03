class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st; // Holds the IDs of the currently running functions
        int prev_time = 0;
        
        for (const string& log : logs) {
            // Manual parsing, similar to your approach but much cleaner
            int first_colon = log.find(':');
            int second_colon = log.find(':', first_colon + 1);
            
            int id = stoi(log.substr(0, first_colon));
            string type = log.substr(first_colon + 1, second_colon - first_colon - 1);
            int time = stoi(log.substr(second_colon + 1));
            
            if (type == "start") {
                // If the stack is not empty, a function is running in the background.
                // We must pause it and give it the time it just spent running.
                if (!st.empty()) {
                    ans[st.top()] += (time - prev_time);
                }
                st.push(id);       // The new function takes over
                prev_time = time;  // Update the clock
            } 
            else {
                // The function at the top of the stack is ending
                int current_running = st.top();
                st.pop(); // Remove it from the active stack
                
                // Give it its final block of time (inclusive, so +1)
                ans[current_running] += (time - prev_time + 1);
                
                // The clock ticks forward to the start of the next second.
                // If there is a function still in the stack, it immediately resumes here.
                prev_time = time + 1;
            }
        }
        
        // Note: Do NOT filter out the 0s at the end. 
        // The problem requires returning exactly 'n' elements. 
        // If a function took 0 time, its index must literally hold the value 0.
        return ans;
    }
};
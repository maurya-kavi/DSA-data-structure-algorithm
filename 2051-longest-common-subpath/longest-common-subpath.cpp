class Solution {
public:
// using map instead of set , reduces the operation for comparing and tC, 
// using double hashing , with single hashing getting WA becuase of the hash collision
    // Double Hashing: We use two distinct prime bases and two distinct prime modulos.
    // This makes the probability of a hash collision astronomically close to zero.

    using ull = unsigned long long;
    const ull m1 = 1e9 + 7;
    const ull m2 = 1e9 + 9;
    const ull b1 = 100003;
    const ull b2 = 100019;

    bool possibleLCS(const vector<vector<int>>& paths, int mid) {
        unordered_map<ull, int> hashCount;

        // Calculate the highest power (hp1 and hp2)
        ull hp1 = 1, hp2 = 1;
        for (int i = 0; i < mid - 1; i++) {
            hp1 = (hp1 * b1) % m1;
            hp2 = (hp2 * b2) % m2;
        }

        for (int i = 0; i < paths.size(); i++) {
            const auto& currPath = paths[i];
            
            if (currPath.size() < mid) return false;

            ull h1 = 0, h2 = 0;
            unordered_set<ull> seenInCurrentPath;

            for (int j = 0; j < mid; j++) {
                h1 = (h1 * b1 + currPath[j]) % m1;
                h2 = (h2 * b2 + currPath[j]) % m2;
            }
            
            // Pack two 32-bit hashes into a single 64-bit integer
            ull combined = (h1 << 32) | h2;
            seenInCurrentPath.insert(combined);

            // rolling hash for other hash val
            for (int j = mid; j < currPath.size(); j++) {
                
                ull drop1 = (currPath[j - mid] * hp1) % m1;
                h1 = (h1 + m1 - drop1) % m1; 
                h1 = (h1 * b1 + currPath[j]) % m1;

                ull drop2 = (currPath[j - mid] * hp2) % m2;
                h2 = (h2 + m2 - drop2) % m2;
                h2 = (h2 * b2 + currPath[j]) % m2;

                combined = (h1 << 32) | h2;
                seenInCurrentPath.insert(combined);
            }

            for (ull h : seenInCurrentPath) {
                hashCount[h]++;
                if (hashCount[h] == paths.size()) {
                    return true;
                }
            }
        }
        return false;
    }
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int l = 1;
        
        int r = paths[0].size();
        for (const auto& path : paths) {
            r = min(r, (int)path.size());
        }

        int ans = 0;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (possibleLCS(paths, mid)) {
                ans = mid;    
                l = mid + 1;  
            } else {
                r = mid - 1;  
            }
        }
        return ans;
    }
};
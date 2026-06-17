class Solution {
private:
bool rabinKarp(string text, string pattern) {
    vector<int> occurrences;
    int n = text.length();
    int m = pattern.length();

    if (m > n || m == 0) return false;

    const int p = 31; // Base prime, standard for lowercase English letters
    const int m_mod = 1e9 + 9; // Large prime modulus to avoid collisions

    long long patternHash = 0;
    long long textHash = 0;
    long long highestPower = 1;

    // Step 1: Precompute the highest power: p^(m-1) % m_mod
    for (int i = 0; i < m - 1; i++) {
        highestPower = (highestPower * p) % m_mod;
    }

    // Step 2: Calculate initial hashes for the pattern and the first window of text
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * p + (pattern[i] - 'a' + 1)) % m_mod;
        textHash = (textHash * p + (text[i] - 'a' + 1)) % m_mod;
    }

    // Step 3: Slide the window over the text
    for (int i = 0; i <= n - m; i++) {
        
        // If the fingerprints match, verify the actual string to rule out collisions
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }

        // Roll the hash forward to the next window
        if (i < n - m) {
            // Subtract the character leaving the window
            textHash = (textHash - (text[i] - 'a' + 1) * highestPower) % m_mod;
            
            // Handle negative values resulting from the modulo arithmetic
            if (textHash < 0) textHash += m_mod; 

            // Multiply by base and add the character entering the window
            textHash = (textHash * p + (text[i + m] - 'a' + 1)) % m_mod;
        }
    }

    return false;
}


public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int count = 1;
        string source = a;
        while(source.size() < b.size()){
            count++;
            source+=a;
        }
        if(source == b) return count;
        if(rabinKarp(source,b)) return count;
        if(rabinKarp(source+a,b)) return count+1;
        return -1;
    }
};
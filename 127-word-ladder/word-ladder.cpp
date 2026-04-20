class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        if(n!=endWord.size()) return 0;
        unordered_set<string>s(wordList.begin(),wordList.end());
        unordered_set<string>vis;

        queue<string>q;
        q.push(beginWord);
        vis.insert(beginWord);
        int steps=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string t=q.front();
                if(t==endWord) return steps;
                q.pop();
                for(char ch='a';  ch<='z'; ch++){
                    for(int i=0; i<n; i++){
                        string p=t;
                        if(p[i]==ch) continue;
                        p[i]=ch;
                        if(vis.find(p)==vis.end() && s.find(p)!=s.end()){
                            //not yet visited and found in the set
                            q.push(p);
                            vis.insert(p);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>genebank(bank.begin(), bank.end());
        unordered_set<string>visited;

        queue<string>q; //to store valid gene mutation
        int mutations=0;
        q.push(startGene);
        //check endgene is in the bank or not
        if(!genebank.count(endGene)) return -1;

        string chars="ACGT";
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string curr=q.front();
                q.pop();
                if(curr==endGene) return mutations;

            for(int i=0; i<curr.size(); i++){
                char original=curr[i];
                for(int j=0; j<chars.size(); j++){
                    if(original==chars[j]) continue;
                    curr[i]=chars[j];
                    if(genebank.count(curr) && !visited.count(curr)){
                        q.push(curr);
                        visited.insert(curr);
                    }
                }
                curr[i]=original;
            }
            }
            mutations++;
        }
        return -1;
    }
};
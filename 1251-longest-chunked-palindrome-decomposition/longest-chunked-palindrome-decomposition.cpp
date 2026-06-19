class Solution {
public:
    int longestDecomposition(string text) {
        string_view sv(text);
        int chunks=0;
        while(!sv.empty()){
            int n=sv.size();
            bool matched=false;
            for(int len=1; len<=n/2; len++){
                if(sv.substr(0,len)==sv.substr(n-len,len)){
                    chunks+=2;

                    sv=sv.substr(len,n-2*len);
                    matched=true;
                    break;
                }
            }
            if(!matched) {
                chunks+=1;
                break;
            }
        }
        return chunks;
    }
};
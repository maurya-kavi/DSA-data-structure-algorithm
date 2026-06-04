class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string>arr={a,b,c};
        sort(arr.begin(), arr.end()); // sort it so we can explore all the permutation
        string result="";
        do{
            string curr=merge(merge(arr[0],arr[1]),arr[2]);
            if(result=="" || result.size()>curr.size() ||
            (result.size()==curr.size() && curr<result)
            ) {
                result=curr;
            }
        }
        while (next_permutation(arr.begin(),arr.end()));
        return result;
    }

private:

    string merge(const string&s1,const string&s2){
        // if s2 is completely insider s1 or s1 is completely inside s2
        if(s1.contains(s2)) return s1;
        if(s2.contains(s1)) return s2;

        int max_overlap=min(s1.length(),s2.length());
        // we iterate backward to greedily find the LARGEST possible overlap first
        for(int i=max_overlap; i>=1; i--){
            // compare the last i character of s1 with the first i characters of s2, so we can get the shortest string off both combined which has both as substring

            if(s1.compare(s1.length()-i, i, s2, 0, i)==0){ // if diff is zero 
                // Bridge them by taking s1 and adding only the un-overlapped part of s2
                return s1 + s2.substr(i);
            }
        }
        return s1+s2; // if no overlapping 
    }
};
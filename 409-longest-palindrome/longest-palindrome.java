class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character,Integer>mp=new HashMap<>();
        // unordered map in c++ , for map TreeMap<Charater,Integer>mp=new TreeMap<>();
        for(char ch:s.toCharArray()){
            mp.put(ch,mp.getOrDefault(ch,0)+1);
        }
int ans=0;
boolean odd=false;
        for(Map.Entry<Character,Integer>entry:mp.entrySet()){
            int freq=entry.getValue();
            if(freq%2==1){
                //odd 
                odd=true;
            }
            ans+=(freq/2);
        }
        ans*=2;
        if(odd) ans++;
return ans;
    }
}
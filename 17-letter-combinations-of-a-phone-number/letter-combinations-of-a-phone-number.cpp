class Solution {
public:
    map<int,string>mp;
    vector<string> letterCombinations(string digits) {
        
        int n=digits.size();
        for(auto ch:digits){
            int x=ch-'0';
            if(x==2) mp[2]="abc";
            else if(x==3) mp[3]="def";
            else if(x==4) mp[4]="ghi";
            else if(x==5) mp[5]="jkl";
            else if(x==6) mp[6]="mno";
            else if(x==7) mp[7]="pqrs";
            else if(x==8) mp[8]="tuv";
            else if(x==9) mp[9]="wxyz";
        }

        vector<string>v;
        for(auto ch:digits){
            int x=ch-'0';
            v.push_back(mp[x]);
        }

        vector<string>ans;
        int m=v.size();
        if(m==1){
            string p=v[0];
            for(int i=0; i<p.size(); i++){
                string x="";
                x+=p[i];
                ans.push_back(x);
            }
            return ans;
        }
        if(m==2){
            string p=v[0];
            string q=v[1];
            for(int i=0; i<p.size(); i++){
                for(int j=0; j<q.size(); j++){
                    char c=p[i];
                    char d=q[j];
                    string x="";
                    x+=c;
                    x+=d;
                    // string x=p[i]+q[j];
                    ans.push_back(x);
                }
            }
            return ans;
        }
        if(m==3){
            string p=v[0];
            string q=v[1];
            string r=v[2];
            for(int i=0; i<p.size(); i++){
                for(int j=0; j<q.size(); j++){
                    for(int k=0; k<r.size(); k++){
                    string x="";
                    x+= (p[i]);
                    x+=q[j];
                    x+=r[k];
                    ans.push_back(x);
                    }
                }
            }
            return ans;
        }
        if(m==4){
            string p=v[0];
            string q=v[1];
            string r=v[2];
            string s=v[3];
            for(int i=0; i<p.size(); i++){
                for(int j=0; j<q.size(); j++){
                    for(int k=0; k<r.size(); k++){
                        for(int l=0; l<s.size(); l++){
                            string x="";
                            x+=p[i];
                            x+=q[j];
                            x+=r[k];
                            x+=s[l];
                            ans.push_back(x);
                        }
                    }
                }
            }
            return ans;
        }
        return ans;
    }
};
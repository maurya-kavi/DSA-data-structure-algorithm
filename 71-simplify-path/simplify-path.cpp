class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st; //store the dir name
        string res;

        res.append("/");
        //to store the name of directory
        string dir;
        int n=path.size();
        for(int i=0; i<path.size(); i++){
            dir.clear();
            while(i<n && path[i]=='/'){
                i++;
            }
            while(i<n && path[i]!='/'){
                dir.push_back(path[i]);
                i++;
            }
            //check if dir=='.' or ".."
            if(dir.compare(".")==0){
                continue;
            }
            else if(dir.compare("..")==0){
                // delete the curr dir to go back prev dir
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(dir.size()!=0){
                st.push(dir);
            }
        }

        // reverse the st 
        stack<string>st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }

        while(!st1.empty()){
            if(st1.size()>1){
                res.append(st1.top() + '/');
            }else{
                res.append(st1.top());
            }
            st1.pop();
        }
        return res;
    }
};
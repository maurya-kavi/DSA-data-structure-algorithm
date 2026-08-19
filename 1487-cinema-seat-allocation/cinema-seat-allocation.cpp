class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // valid seat block for a group of 4 person
        bool s1=true, s2=true, s3=true;
        int m=reservedSeats.size();
sort(reservedSeats.begin(), reservedSeats.end());

int row=1;
int i=0;
int ans=0;
        while(i<m && row<=n){
            while(i<m && reservedSeats[i][0]==row){
                if(reservedSeats[i][1]==2 || reservedSeats[i][1]==3 || reservedSeats[i][1]==4 || reservedSeats[i][1]==5){
                    s1=false;
                }
                if(reservedSeats[i][1]==4 || reservedSeats[i][1]==5 || reservedSeats[i][1]==6 || reservedSeats[i][1]==7){
                    s2=false;
                }
                if(reservedSeats[i][1]==6 || reservedSeats[i][1]==7 || reservedSeats[i][1]==8 || reservedSeats[i][1]==9){
                    s3=false;
                }
                i++;        
            }

                if((s1 && s2 && s3) || (s1 && s3)){
                    ans+=2; // s1 and s3
                }
                else if((s1 && s2) || (s2 && s3)) ans+=1;
                else if(s1 || s2 || s3) ans+=1;
                
                s1=true;
                s2=true;
                s3=true;

                row++;
                // i++;

        }

        if(row<=n){
            ans+=(n-row+1)*2;
        }

        return ans;
    }
};
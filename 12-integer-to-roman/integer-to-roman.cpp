class Solution {
public:
    string intToRoman(int num) {
        //cal no of digit
        int k=0;
        int temp=num;
        while(temp>0){
            k++;
            temp/=10;
        }
        int n=k;
        //no of digit before digit
        k-=1;
        int t=0;
        string ans="";
        for(int i=0; i<n; i++){
            int digit=num%10;
            num/=10;
            // t++;
            if((digit!=4 && digit!=9) && digit<5){
                for(int j=0; j<digit; j++){
                if(t==3){
                    ans.push_back('M');
                }
                if(t==2){
                    ans.push_back('C');
                }
                if(t==1){
                    ans.push_back('X');
                }
                if(t==0){
                    ans.push_back('I');
                }
                }
            }

            if((digit!=4 && digit!=9) && digit>=5){
                char ch;
                if(t==2) ch='D';
                if(t==1) ch='L';
                if(t==0) ch='V';
                digit-=5;
                for(int j=0; j<digit; j++){
                if(t==2){
                    ans.push_back('C');
                }
                if(t==1){
                    ans.push_back('X');
                }
                if(t==0){
                    ans.push_back('I');
                }
                }
                ans.push_back(ch);
            }
            if(digit==4){
                if(t==2){
                    ans.push_back('D');
                    ans.push_back('C');
                }
                if(t==1){
                    ans.push_back('L');
                    ans.push_back('X');
                }
                if(t==0){
                    ans.push_back('V');
                    ans.push_back('I');
                }
            }
            if(digit==9){
                if(t==2){
                    ans.push_back('M');
                    ans.push_back('C');
                }
                if(t==1){
                    ans.push_back('C');
                    ans.push_back('X');
                }
                if(t==0){
                    ans.push_back('X');
                    ans.push_back('I');
                }
            }
            t++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
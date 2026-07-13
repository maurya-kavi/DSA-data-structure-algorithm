class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v;
        // for 2 digit
        v.push_back(12);
        v.push_back(23);
        v.push_back(34);
        v.push_back(45);
        v.push_back(56);
        v.push_back(67);
        v.push_back(78);
        v.push_back(89);

        //for 3 digit
        v.push_back(123);
        v.push_back(234);
        v.push_back(345);
        v.push_back(456);
        v.push_back(567);
        v.push_back(678);
        v.push_back(789);

        //for 4 digit
        v.push_back(1234);
        v.push_back(2345);
        v.push_back(3456);
        v.push_back(4567);
        v.push_back(5678);
        v.push_back(6789);


        // for 5 digit

        v.push_back(12345);
        v.push_back(23456);
        v.push_back(34567);
        v.push_back(45678);
        v.push_back(56789);

        // for 6 digit
        v.push_back(123456);
        v.push_back(234567);
        v.push_back(345678);
        v.push_back(456789);

        //for 7 digit
        v.push_back(1234567);
        v.push_back(2345678);
        v.push_back(3456789);

        // for 8 digit
        v.push_back(12345678);
        v.push_back(23456789);

        // for 9 digit
        v.push_back(123456789);


        int lb=lower_bound(v.begin(),v.end(),low)-v.begin();
        int ub=upper_bound(v.begin(),v.end(),high)-v.begin();
vector<int>ans;
        for(int i=lb; i<ub; i++){
            ans.push_back(v[i]);
        }
return ans;
    }
};
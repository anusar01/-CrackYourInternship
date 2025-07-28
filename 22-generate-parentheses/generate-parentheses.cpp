class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(0,0,"",res,n);
        return res;
    }


    void helper(int l,int r,string s,vector<string> &res,int n){
        if(l==r && l+r==2*n){
            res.push_back(s);
            return;
        }

        if(l<n){
            helper(l+1,r,s+"(",res,n);
        }

        if(r<l){
            helper(l,r+1,s+")",res,n);
        }
    }
};
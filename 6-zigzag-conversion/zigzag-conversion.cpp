class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        vector<vector<char>> rows(numRows);
        int ind=0;
        int d=1;
        for(char c:s){
            rows[ind].push_back(c);
            if(ind==0){
                d=1;
            }else if(ind==numRows-1){
                d=-1;
            }
            ind+=d;
        }
        string res;
        for(const auto& row:rows){
            for(char r:row){
                res+=r;
            }
        }
        return res;
    }
};
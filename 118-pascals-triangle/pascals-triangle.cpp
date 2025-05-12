class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=0;i<numRows-1;i++){
            vector<int> dummy={0};
            dummy.insert(dummy.end(),res.back().begin(),res.back().end());
            dummy.push_back(0);
            vector<int> row;
            for(int j=0;j<dummy.size()-1;j++){
                row.push_back(dummy[j]+dummy[j+1]);
            }
            res.push_back(row);
        }
        return res;
    }
};
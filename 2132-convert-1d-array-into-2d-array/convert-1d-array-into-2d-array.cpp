class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> newarray;
        //edge cases
        if(m*n!=original.size()){
            return newarray;
        }
        for(int i=0;i<m;i++){
            vector<int> curr;
            for(int j=0;j<n;j++){
                curr.push_back(original[j+n*i]);
            }
            newarray.push_back(curr);
        }
        return newarray;    
    }
};
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> single;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                single.push_back(grid[i][j]);
            }
        }
        sort(single.begin(),single.end());
        vector<int> res;
        int doub,nf;
        for(int i=0;i<n*n;i++){
            if((i+1)<n*n && single[i]==single[i+1]){
                doub=single[i];
                continue;
            }
            if((i+1)<n*n && single[i]+1!=single[i+1]){
                nf=single[i]+1;
            }
            if(single[n*n-1]!=n*n){
                nf=n*n;
            }
            if(single[0]!=1){
                nf=1;
            }
        }
        res.push_back(doub);
        res.push_back(nf);
        return res;
    }
};
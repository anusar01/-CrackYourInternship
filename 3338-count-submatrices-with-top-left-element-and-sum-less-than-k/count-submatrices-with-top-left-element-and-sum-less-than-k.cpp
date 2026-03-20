class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> sum(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+grid[i][j];
                ans+=(sum[i+1][j+1]<=k)?1:0;;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int currgrid(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=grid[i][j]+min(currgrid(grid,i-1,j,dp),currgrid(grid,i,j-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return currgrid(grid,n-1,m-1,dp);
    }
};
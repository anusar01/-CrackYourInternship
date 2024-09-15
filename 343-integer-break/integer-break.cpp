class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        if(n<=1){
            return 0;
        }
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                dp[i]=max(i/2,dp[i/2])*max(i/2,dp[i/2]);
                dp[i]=max(dp[i],max(i/2-1,dp[(i/2)-1])*max(i/2+1,dp[(i/2)+1]));
            }else{
                dp[i]=max(i/2,dp[i/2])*max(i/2+1,dp[(i/2)+1]);
                dp[i]=max(dp[i],max(i/2-1,dp[(i/2)-1])*max(i/2+2,dp[(i/2)+2]));
            }
        }
        return dp[n];
    }
};
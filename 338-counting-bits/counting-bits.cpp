class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        if(n>=1){
            dp[1]=1;
        }
        for(int i=2;i<=n;i++){
            if(i%2==0){
                dp[i]=dp[i/2];
            }else{
                dp[i]=dp[i/2]+1;
            }
        }
        return dp;
    }
};
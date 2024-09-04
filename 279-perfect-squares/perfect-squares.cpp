class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        vector<int> perfectsq;
        //given a number find all perfect square lesser than that
        
        for(int i=1;i*i<=n;i++){
            perfectsq.push_back(i*i);
        }
        //ab dp array mai krna hai
        for(int i=2;i<=n;i++){
            for(int j=0;j<perfectsq.size();j++){
                if(i>=perfectsq[j]){
                dp[i]=min(dp[i],1+dp[i-perfectsq[j]]);
                }
            }
        }
        return dp[n];
    }
};
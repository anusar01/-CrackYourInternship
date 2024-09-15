class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1);
        if(n==0){
            return 1;
        }
        if (n==1){
            return 10;
        }
        dp[0]=0;
        dp[1]=10;
        int k=9;
        for(int i=0;i<n-1;i++){
            k*=(9-i);
            //PnC concept hai
            dp[i+2]=dp[i+1]+k;
        }
        return dp[n];
    }
};
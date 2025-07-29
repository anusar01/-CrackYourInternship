class Solution {
public:
//this returns the length 
//we need to find the count of those
    // int solve(int n,vector<int> nums,int curr,int prev,vector<vector<int>> &dp){
    //     if(curr==n){
    //         return 0;
    //     }
    //     if(dp[curr][prev+1]!=-1){
    //         return dp[curr][prev+1];
    //     }
    //     int take=0;
    //     if(prev==-1||nums[curr]>nums[prev]){
    //         take=1+solve(n,nums,curr+1,curr,dp);
    //     }
    //     int nottake=0+solve(n,nums,curr+1,prev,dp);
    //     return dp[curr][prev+1]=max(take,nottake);
    // }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){return 0;}
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxlen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }else if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        int result = 0;
        for(int i = 0; i < n; ++i) {
            if(dp[i] == maxlen) {
                result += count[i];
            }
        }

        return result;
    }
};
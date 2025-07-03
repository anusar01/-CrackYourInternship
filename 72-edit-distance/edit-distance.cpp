class Solution {
public:
    int minelstr(int i,string word1,int j,string word2,vector<vector<int>>& dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=0+minelstr(i-1,word1,j-1,word2,dp);
        }else{
            return dp[i][j]=1+min(minelstr(i,word1,j-1,word2,dp),
            min(minelstr(i-1,word1,j,word2,dp),minelstr(i-1,word1,j-1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int i=word1.size(),j=word2.size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return minelstr(i-1,word1,j-1,word2,dp);
    }
};
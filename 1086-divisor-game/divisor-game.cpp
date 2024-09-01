class Solution {
public:
    bool divisorGame(int n) {
        //dp use krna hai
        vector<int> dp(n+1,0);
        dp[1]=0;//koi move hi nhi hai
        for(int i=2;i<=n;i++){
            for(int x=1;x<i;x++){
                if(i%x==0 && dp[i-x]==0){
                    dp[i]=1;
                    break;//kyunki yahi mil gaya to aage next i ka dekh
                }
            }
        }
        return dp[n]==1;
        
        //if even hai to bas alice hi jeet sakta but odd mai bob ka possible hai
        /*if(n%2==0){
            return true;
        }else{
            return false;
        }*/
    }
};
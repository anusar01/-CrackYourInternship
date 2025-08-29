class Solution {
public:
    long long flowerGame(int n, int m) {
        //odd num in any one and both shouldnt be equal
        //for each val in 1..n find how many from 1..m whic is different
        long long ans=0;
        int even_ct=0;
        int odd_ct=0;
        for(int j=1;j<=m;j++){
            if(j%2==0){
                even_ct++;
            }else{
                odd_ct++;
            }
        }
        for(int i=1;i<=n;i++){
            //in range 1..m find how many odd and even
            if(i%2==0){
                ans+=odd_ct;
            }else{
                ans+=even_ct;
            }
        }
        return ans;
    }
};
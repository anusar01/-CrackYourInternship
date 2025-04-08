class Solution {
public:
    long long numberOfWays(string s) {
        //3 valid buildings
        int n=s.length();
        //only valid pattern 010 101
        long long a=0,b=0,c=0,d=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                a++;
            }else{
                b++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans+=b*d;
                c++;
                a--;
            }else{
                ans+=a*c;
                b--;d++;
            }
        }
        return ans;

    }
};
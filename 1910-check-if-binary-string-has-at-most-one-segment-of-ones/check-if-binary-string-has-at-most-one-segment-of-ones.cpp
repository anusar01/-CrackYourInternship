class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c++;
                while(s[i]=='1'){
                    i++;
                }
            }
        }
        if(c==1){
            return true;
        }
        return false;
    }
};
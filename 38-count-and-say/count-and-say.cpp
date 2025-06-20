class Solution {
public:
    string countAndSay(int n) {
        string ans="1"; 
        if(n==1){
            return ans;
        }
        return rle(countAndSay(n-1));
    }
    string rle(const string &s){
        string result;
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                result+=to_string(count)+s[i-1];
                count=1;
            }
        }
        result+=to_string(count)+s.back();
        return result;
    }
};
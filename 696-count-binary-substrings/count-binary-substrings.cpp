class Solution {
public:
    int countBinarySubstrings(string s) {
      int count=0;
      int prev=0,cur=1;
      for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1]){
            count+=min(prev,cur);
            prev=cur;
            cur=1;
        }else{
            cur++;
        }
      }  
      return count+min(prev,cur);
    }
};
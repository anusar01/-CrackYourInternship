class Solution {
public:
    int minOperations(string s) {
        //find s for bot 1010... 0101...
        int count_even_0=0;
        int count_odd_0=0;
        int count_even_1=0;
        int count_odd_1=0;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
            if(s[i]=='0'){
                count_odd_0++;
            }else{
                count_odd_1++;
            }}else{
               if(s[i]=='0'){
                count_even_0++;
            }else{
                count_even_1++;
            } 
            }
        }
        return min((count_even_0+count_odd_1),(count_even_1+count_odd_0));
    }
};
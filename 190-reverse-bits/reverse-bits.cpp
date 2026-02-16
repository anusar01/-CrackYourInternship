class Solution {
public:
    //number to binary
    string convert_to_binary(int n){
        string bin_n="";
        while(n>0){
            bin_n=char('0'+(n%2))+bin_n;
            n/=2;
        }
        while(bin_n.size()<32){
            bin_n='0'+bin_n;
        }
        return bin_n;
    }
    int bin_to_num(string bin){
        int res=0;
        long long v=1;
        for(int i=31;i>=0;i--){
            if(bin[i]=='1'){
                res+=v;
            }
            v=v*2;
        }
        return res;
    }
    int reverseBits(int n) {
        string bin_n=convert_to_binary(n);
        reverse(bin_n.begin(),bin_n.end());
        int res=bin_to_num(bin_n);
        return res;
    }
};
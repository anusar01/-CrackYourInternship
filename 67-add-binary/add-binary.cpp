class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length();
        int m=b.length();
        int final=n>m?n:m;
        while(a.length()!=final){
            a="0"+a;
        }
        while(b.length()!=final){
            b="0"+b;
        }
        char c='0';
        string res="";
        for(int i=final-1;i>=0;i--){
            if(a[i]=='0' && b[i]=='0' && c=='0'){
                res = '0' + res;
                c='0';
            }
            else if(a[i]=='0' && b[i]=='0' && c=='1'){
                res = '1' + res;
                c='0';
            }
            else if(a[i]=='0' && b[i]=='1' && c=='0'){
                res = '1' + res;
                c='0';
            }
            else if(a[i]=='0' && b[i]=='1' && c=='1'){
                res = '0' + res;
                c='1';
            }
            else if(a[i]=='1' && b[i]=='0' && c=='0'){
                res = '1' + res;
                c='0';
            }
            else if(a[i]=='1' && b[i]=='0' && c=='1'){
                res = '0' + res;
                c='1';
            }
            else if(a[i]=='1' && b[i]=='1' && c=='0'){
                res = '0' + res;
                c='1';
            }
            else if(a[i]=='1' && b[i]=='1' && c=='1'){
                res = '1' + res;
                c='1';
            }
        }
        if(c=='1'){
            res=c+res;
        }
        return res;
    }
};
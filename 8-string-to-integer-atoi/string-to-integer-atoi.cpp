class Solution {
public:
    int myAtoi(string s) {
        long res=0;
        int sign=1;
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '&& c==0){continue;}
            else if((s[i]=='-'||s[i]=='+')&& c==0){sign = (s[i] == '-') ? -1 : 1;
                c = 1;}
            else if(isdigit(s[i])){
                c=1;
                int digit = s[i] - '0';
                res=res*10+digit;
                if(sign == 1 && res > INT_MAX) return INT_MAX;
                if(sign == -1 && -res < INT_MIN) return INT_MIN;}
            else{break;}
        }
        
        return res*sign;
    }
};
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int num=n;
        int bit=num%2;
        num/=2;
        while(num>0){
            if(bit==num%2){
                return false;
            }
            bit=num%2;
            num/=2;
        }
        return true;
    }
};
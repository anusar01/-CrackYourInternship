class Solution {
public:
    bool divisorGame(int n) {
        //if even hai to bas alice hi jeet sakta but odd mai bob ka possible hai
        if(n%2==0){
            return true;
        }else{
            return false;
        }
    }
};
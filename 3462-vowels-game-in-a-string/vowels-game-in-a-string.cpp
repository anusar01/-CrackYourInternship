class Solution {
public:
    bool doesAliceWin(string s) {
        map<char,int> vowels;
        vowels['a']=1;
        vowels['e']=1;
        vowels['i']=1;
        vowels['o']=1;
        vowels['u']=1;
        int count_vowels=0;
        for(char c:s){
            if(vowels.find(c)!=vowels.end()){
                count_vowels++;
            }
        }
        //now alice wins only if count_vowels is even
        if(count_vowels==0){
            return false;
        }
        return true;
    }
};
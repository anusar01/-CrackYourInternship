class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int count=0;
        while(ss>>word){
            int f=0;
            for(char c:brokenLetters){
                if(word.find(c)!=string::npos){
                    f=1;
                    break;
                }
            }
            if(f==0){
                count++;
            }
        }
        return count;
    }
};
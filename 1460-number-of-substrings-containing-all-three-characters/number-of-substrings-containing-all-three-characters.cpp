class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int left=0;
        unordered_map<char,int> count_char={{'a',0},{'b',0},{'c',0}};
        for(int right=0;right<s.length();right++){
            count_char[s[right]]++;
            while(count_char['a']>0 && count_char['b']>0 && count_char['c']>0){
                count+=s.length()-right;
                count_char[s[left]]--;
                left++;
            }
        }
        return count;
    }
};
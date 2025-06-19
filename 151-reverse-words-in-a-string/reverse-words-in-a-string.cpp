class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int start;
        int end;
        int i=0;
        while(i<s.length()){
            start=i;
            end=i;
            while(end!=s.length() && s[end]!=' '){end++;}
            string word = s.substr(start, end - start);
            if (ans.empty()) {
                ans = word;
            } else {
                ans = word + " " + ans;
            }
            while(s[end]==' '){end++;}
            i=end;

        }
        return ans;
    }
};
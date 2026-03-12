class Solution {
public:
    int minFlips(string s) {
        string t = s + s;
        int n = s.length();

        int pattern1 = INT_MAX;
        int pattern2 = INT_MAX;

        int d1 = 0, d2 = 0;

        for(int i = 0; i < t.length(); i++){

            if(t[i] != (i % 2 ? '1' : '0')) d1++;
            if(t[i] != (i % 2 ? '0' : '1')) d2++;

            if(i >= n){
                if(t[i-n] != ((i-n) % 2 ? '1' : '0')) d1--;
                if(t[i-n] != ((i-n) % 2 ? '0' : '1')) d2--;
            }

            if(i >= n-1){
                pattern1 = min(pattern1, d1);
                pattern2 = min(pattern2, d2);
            }
        }

        return min(pattern1, pattern2);
    }
};
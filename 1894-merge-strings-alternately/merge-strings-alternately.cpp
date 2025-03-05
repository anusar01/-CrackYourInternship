class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        int i=0,j=0;
        string merged="";
        while(i<n1 && j<n2){
            merged+=word1[i];
            i++;
            merged+=word2[j];
            j++;
        }
        while(i<n1){
            merged+=word1[i];
            i++;
        }
        while(j<n2){
            merged+=word2[j];
            j++;
        }
        return merged;
    }
};
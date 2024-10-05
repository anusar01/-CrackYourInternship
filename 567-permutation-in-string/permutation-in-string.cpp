class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //return true if the string s1 in any order is present
        //as a substring in s2
        //we can do one thing s1 ko sort krle and s2 mai se s1 length ka retrieve krti reh till end and sort and compare
        int l1=s1.length();
        int l2=s2.length();
        //sort s1
        sort(s1.begin(),s1.end());
        
        for(int i=0;i<l2-l1+1;i++){
            string s3;
            for(int j=i;j<i+l1;j++){
                s3+=s2[j];
            }
            sort(s3.begin(),s3.end());
            
            if(s3==s1){
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    int minimumDeletions(string s) {
       //in thestring we need to keep only a in front and b at end
       //for these remove a and b in middle
       //find the min deletions
       //find num of b in between first and last 
       int count_a_after=0;
       int count_b_before=0;
       int n=s.length();
       vector<int> count_a(n,0);
        vector<int> count_b(n,0);

        for(int i=0;i<n;i++){
            count_b[i]=count_b_before;
            if(s[i]=='b') count_b_before++;
        }

        for(int i=n-1;i>=0;i--){
            count_a[i]=count_a_after;
            if(s[i]=='a') count_a_after++;
        }

        int mindel=n;
        for(int i=0;i<n;i++){
            mindel=min(mindel,count_a[i]+count_b[i]);
        }
        return mindel;


    }
};
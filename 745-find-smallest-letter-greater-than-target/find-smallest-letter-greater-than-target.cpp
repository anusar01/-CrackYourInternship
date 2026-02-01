class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0;
        int high=letters.size()-1;
        int mid;
        //int c=target+1;
        char r=target;
        int ans=0;
        while(high>=low){
            mid=(low+high)/2;
        if(r < letters[mid]){
            high=mid-1;
            ans=mid;
        }else{
            low=mid+1;
        }
        }
        return letters[ans];
    }
};
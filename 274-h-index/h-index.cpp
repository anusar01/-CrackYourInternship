class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int s=citations.size();
        
        for(int i=0;i<s;i++){
            if(citations[i]>=s-i ){
                return s-i;
            }
        }
        return 0;
    }
};
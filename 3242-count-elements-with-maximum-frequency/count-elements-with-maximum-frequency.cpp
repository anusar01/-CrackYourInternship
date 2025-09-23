class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq_count;
        int count=1;
        for(int n:nums){
            if(freq_count.find(n)!=freq_count.end()){
                freq_count[n]++;
                count=max(count,freq_count[n]);
            }else{
                freq_count[n]=1;
            }
        }
        int total=0;
        for(auto m:freq_count){
            if(m.second==count){
                total+=count;
            }
        }
        return total;
    }
};
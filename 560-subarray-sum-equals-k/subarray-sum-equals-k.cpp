class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefix sum array;
        int n=nums.size();
        vector<int> prefix;
        int p=0;
        for(int i:nums){
            p+=i;
            prefix.push_back(p);
        }
        //prefix vector ban jayega
        //then ham ek bar array ko traverse krenge 
        //agar target mil gaya to count bada de
        //next two pointer lagayegi and check kregi agar kisika bhi difference
        //same hai to count++
        int count=0;
        unordered_map<int,int> mp;
        //if subarray start from begining
        for(int j:prefix){
            if(j==k){
                count++;
            }
            if(mp.find(j-k)!=mp.end()){
                count+=mp[j-k];
            }
            mp[j]++;
        }
        
        return count;     
    }
};
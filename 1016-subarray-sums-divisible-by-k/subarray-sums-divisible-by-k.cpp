class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int n=nums.size();
       int count=0;
       int sum=0;
       unordered_map<int,int> m;
       m[0]=1;
       //for case where the whole array is zero
       for(int i:nums){
        sum+=i;
        int mod=sum%k;
        if(mod<0){
            mod+=k;
        }
        if(m.find(mod)!=m.end()){
            count+=m[mod];
        }
        m[mod]++;
       }
       return count;
    }
};
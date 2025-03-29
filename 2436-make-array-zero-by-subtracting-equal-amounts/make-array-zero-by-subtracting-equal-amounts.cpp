class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        while(nums[nums.size()-1]!=0){
        
        int i=0;
        while(nums[i]==0){
            i++;
        }
        int curr=nums[i];
        for(int j=i;j<nums.size();j++){
            nums[j]-=curr;
        }
        count++;}
        return count;
    }
};
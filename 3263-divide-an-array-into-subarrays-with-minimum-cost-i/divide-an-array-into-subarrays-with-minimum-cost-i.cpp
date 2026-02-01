class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first=nums[0];
        int least=nums[1];
        int small=nums[2];
        for(int i=2;i<nums.size();i++){
            if(least>=nums[i]){
                small=least;
                least=nums[i];
                continue;
            }
            if(small>nums[i]){
                small=nums[i];
            }
        }
        return first+least+small;
    }
};
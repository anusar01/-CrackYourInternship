class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int diff=0;
        int count=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                if(diff==1||diff==0){
                    diff=-1;
                    count++;
                }
            }else if(nums[i]>nums[i+1]){
                if(diff==-1||diff==0){
                    diff=1;
                    count++;
                }
            }
        }
        return count;
    }
};
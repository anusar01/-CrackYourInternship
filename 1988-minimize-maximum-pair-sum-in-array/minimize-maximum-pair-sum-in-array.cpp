class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxSum=INT_MIN;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<(n/2)+1;i++){
            if(maxSum<(nums[i]+nums[n-i-1])){
                maxSum=nums[i]+nums[n-i-1];
            }
        }
        return maxSum;
    }
};
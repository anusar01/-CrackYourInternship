class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1){return 0;}
        int mindiff=INT_MAX;
        for(int i=0;i<nums.size()-k+1;i++){
            if(nums[i+k-1]-nums[i]<mindiff){
                mindiff=nums[i+k-1]-nums[i];
            }
        }
        return mindiff;
    }
};
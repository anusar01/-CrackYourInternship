class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ch=0;
        int i;
        for(i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                ch=1;
                i--;
                break;
            }
        }
        if(ch==1){
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[i]){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
        }
        if(ch==0){
            reverse(nums.begin(),nums.end());
        }
    }
};
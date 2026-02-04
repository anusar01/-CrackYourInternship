class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=-1,q=-1,r=-1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                continue;
            }else{
                p=i;
                break;
            }
        }
         if(p==-1 || p<=1){
            return false;
        }

        for(int i=p;i<n;i++){
            if(nums[i]<nums[i-1]){
                continue;
            }else{
                q=i;
                break;
            }
        }
        if(q==-1 || q-p<1){
            return false;
        }
        
        for(int i=q;i<n;i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }

          
        // if( n-q<2){
        //     return false;
        // }
        return true;
    }
};
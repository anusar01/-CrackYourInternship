#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cmath>

class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        //use dp
        map<int,int> mp;
        sort(nums.begin(),nums.end());
        int res=-1;
        for(int num:nums){
            int numsqrt=sqrt(num);
            if(numsqrt*numsqrt==num && mp.find(numsqrt)!=mp.end()){
                mp[num]=mp[numsqrt]+1;
                res=max(res,mp[num]);
            }else{
                mp[num]=1;
            }
        }
        return res;
    }
};

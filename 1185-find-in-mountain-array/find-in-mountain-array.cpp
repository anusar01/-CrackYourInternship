/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if (mountainArr.length()<3) return -1;
        int l=0,r=mountainArr.length()-1;
        int mid;
        while(l<r){
            mid=(l+r)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        mid=l;
        l=0;
        int curr_r=mid;
        r=mountainArr.length()-1;
        while(l<=curr_r){
            int mid_1=(l+curr_r)/2;
            if(mountainArr.get(mid_1)==target){
                return mid_1;
            }else if(mountainArr.get(mid_1)<target){
                l=mid_1+1;
            }else{
                curr_r=mid_1-1;
            }
        }
        int curr_l=mid;
        while(curr_l<=r){
            int mid_2=(r+curr_l)/2;
            if(mountainArr.get(mid_2)==target){
                return mid_2;
            }else if(mountainArr.get(mid_2)<target){
                r=mid_2-1;
            }else{
                curr_l=mid_2+1;
            }
        }
        return -1;
    }
};
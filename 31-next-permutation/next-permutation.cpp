class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ch = 0;
        int i;

        // Step 1: Find first decreasing element from the right
        for (i = n - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                ch = 1;
                i--; // Move to the element to be swapped
                break;
            }
        }

        if (ch == 1) {
            // Step 2: Find the next greater element to the right of nums[i]
            for (int j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            // Step 3: Reverse the suffix starting from i+1
            reverse(nums.begin() + i + 1, nums.end());
        } else {
            // Step 4: No pivot found, reverse entire array
            reverse(nums.begin(), nums.end());
        }
    }
};

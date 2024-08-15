class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxval = nums[0];  // Initialize maxval to the first element
        long long prod = 1;
        const long long limit = LLONG_MAX / 10;  // Define a safe limit to prevent overflow
        
        // Traverse from left to right
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            maxval = max(maxval, prod);
            if (prod == 0) {
                prod = 1;  // Reset product if zero is encountered
            } else if (abs(prod) > limit) {
                prod = 1;  // Reset product if it exceeds the safe limit
            }
        }
        
        prod = 1;  // Reset prod for reverse traversal
        
        // Traverse from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxval = max(maxval, prod);
            if (prod == 0) {
                prod = 1;  // Reset product if zero is encountered
            } else if (abs(prod) > limit) {
                prod = 1;  // Reset product if it exceeds the safe limit
            }
        }
        
        return static_cast<int>(maxval);  // Cast back to int before returning
    }
};

class Solution {
public:
    int myAtoi(string s) {
        long res = 0;           // Use long to handle overflow
        int sign = 1;
        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && c == 0) {
                continue; // Skip leading spaces
            }
            else if ((s[i] == '-' || s[i] == '+') && c == 0) {
                sign = (s[i] == '-') ? -1 : 1;
                c = 1; // Mark that sign/number has started
            }
            else if (isdigit(s[i])) {
                c = 1; // Mark that number parsing started
                int digit = s[i] - '0';
                res = res * 10 + digit;

                // Check for overflow
                if (sign == 1 && res > INT_MAX) return INT_MAX;
                if (sign == -1 && -res < INT_MIN) return INT_MIN;
            }
            else {
                break; // Non-digit, non-space, non-sign char ends parsing
            }
        }
        return res * sign;
    }
};

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumroll = accumulate(rolls.begin(), rolls.end(), 0); // Sum of given rolls
        int missnval = (mean * (m + n)) - sumroll; // Total sum needed for missing rolls
        
        // If it's impossible to distribute the missing values
        if (missnval < n || missnval > 6 * n) {
            return {}; // Empty array
        }

        vector<int> missarray(n, 1); // Start with all ones
        missnval -= n; // Subtract n because we already have n "1"s

        // Distribute the remaining sum across the missing rolls
        for (int i = 0; i < n && missnval > 0; i++) {
            int add = min(5, missnval); // We can add at most 5 (to keep within the range 1-6)
            missarray[i] += add;
            missnval -= add;
        }

        return missarray;
    }
};

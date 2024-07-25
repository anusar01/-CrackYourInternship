class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalsum = 0;
        
        for (int i : cardPoints) {
            totalsum += i;
        }
        
        // Calculate the sum of the first `n - k` elements
        int currsum = 0;
        for (int i = 0; i < n - k; ++i) {
            currsum += cardPoints[i];
        }
        
        int maxsum = totalsum - currsum;
        
        // Slide the window and find the maximum sum
        for (int i = 0; i < k; ++i) {
            currsum = currsum - cardPoints[i] + cardPoints[n-k+i];
            maxsum = max(maxsum, totalsum - currsum);
        }
        
        return maxsum;
    }
};

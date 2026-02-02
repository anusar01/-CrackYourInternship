class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        // multiset to maintain k-1 smallest elements
        multiset<int> small, large;
        long long sumSmall = 0;

        // helper lambdas
        auto add = [&](int x) {
            if (small.size() < k - 1) {
                small.insert(x);
                sumSmall += x;
            } else if (!small.empty() && x < *prev(small.end())) {
                large.insert(*prev(small.end()));
                sumSmall -= *prev(small.end());
                small.erase(prev(small.end()));
                small.insert(x);
                sumSmall += x;
            } else {
                large.insert(x);
            }
        };

        auto remove = [&](int x) {
            if (small.find(x) != small.end()) {
                small.erase(small.find(x));
                sumSmall -= x;
                if (!large.empty()) {
                    auto it = large.begin();
                    small.insert(*it);
                    sumSmall += *it;
                    large.erase(it);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        // sliding window [1 ... dist+1]
        for (int i = 1; i <= dist + 1 && i < n; i++) {
            add(nums[i]);
        }

        if (small.size() == k - 1) {
            ans = min(ans, sumSmall);
        }

        // slide the window
        for (int i = dist + 2; i < n; i++) {
            remove(nums[i - dist - 1]);
            add(nums[i]);

            if (small.size() == k - 1) {
                ans = min(ans, sumSmall);
            }
        }
        return nums[0] + ans;

    }
};
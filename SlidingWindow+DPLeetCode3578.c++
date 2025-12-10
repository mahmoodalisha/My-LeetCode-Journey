//window ko tab tak shrink karo jab tak usme max-min<=k na ho jaye
//dp array me result ko store karlo phir
//har window me iterate karke check karna padega max aur min element, iske liye dequeue use karlo O(1) me ho jayega
class Solution {
public:
    static constexpr int MOD = 1000000007;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        vector<long long> prefix(n + 1, 0);

        dp[0] = 1;
        prefix[0] = 1;

        deque<int> maxQ; // decreasing -> front = max index
        deque<int> minQ; // increasing -> front = min index

        int left = 0;
        for (int right = 0; right < n; ++right) {
            // Maintain MAX deque (decreasing)
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(right);

            // Maintain MIN deque (increasing)
            while (!minQ.empty() && nums[minQ.back()] >= nums[right]) {
                minQ.pop_back();
            }
            minQ.push_back(right); 

            // Shrink window while condition violated
            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > k) {
                if (maxQ.front() == left) maxQ.pop_front();
                if (minQ.front() == left) minQ.pop_front();
                ++left;
            }

            long long ways = prefix[right];            // sum of dp[0..right-1]
            if (left > 0) ways = (ways - prefix[left - 1] + MOD) % MOD;

            dp[right + 1] = ways;
            prefix[right + 1] = (prefix[right] + dp[right + 1]) % MOD;
        }

        return (int) dp[n];
    }
};
//youtube : study placement
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int sum = 0;
        int maxNegative = INT_MIN;
        bool hasPositive = false;

        for (int num : nums) {
            if (seen.count(num)) continue;
            seen.insert(num);

            if (num > 0) {
                sum += num;
                hasPositive = true;
            } else {
                maxNegative = max(maxNegative, num);
            }
        }

        return hasPositive ? sum : maxNegative;
    }
};

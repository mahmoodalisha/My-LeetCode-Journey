class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum_A = accumulate(begin(aliceSizes), end(aliceSizes), 0);
        int sum_B = accumulate(begin(bobSizes), end(bobSizes), 0);
        int target = (sum_B - sum_A) / 2;
        unordered_set<int> set_B(bobSizes.begin(), bobSizes.end());
        for (int x : aliceSizes) {
            int y = x + target;
            if (set_B.count(y)) {
                return {x, y}; // Alice gives x, Bob gives y
            }
        }
        return {}; // guaranteed answer exists, so technically ye kabhi nahi chalega
    }
};
/*
Input: aliceSizes = [1,1], bobSizes = [2,2]
How accumulate works here 
sum_A = 0 + 1 + 1 = 2
sum_B = 0 + 2 + 2 = 4
Final values:
sum_A = 2
sum_B = 4
*/
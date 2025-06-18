/*Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers sum to target


Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 */


class Solution {
    public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> combination, int start) {
    // Base case: if target becomes 0, we've found a valid combination
    if (target == 0) {
    result.push_back(combination);
    return;
    }
// Try each candidate starting from the current index `start`
    for (int i = start; i < candidates.size(); i++) {
// If the candidate exceeds the target, skip it
    if (candidates[i] > target) continue;

// Include the current candidate in the combination
    combination.push_back(candidates[i]);

// Since we can reuse the same element, call backtrack with the same `i`
    backtrack(candidates, target - candidates[i], result, combination, i);
// Backtrack by removing the last added element
    combination.pop_back();
    }
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    backtrack(candidates, target, result, combination, 0);
    return result;
    }
};

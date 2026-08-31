class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<pair<int, int>> arr;

        // Store {value, index}
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value in descending order
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        // Keep k largest elements
        arr.resize(k);

        // Sort selected elements by their original index
        sort(arr.begin(), arr.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<int> result;

        for (auto& p : arr) {
            result.push_back(p.first);
        }

        return result;
    }
};
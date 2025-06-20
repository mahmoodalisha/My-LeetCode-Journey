/*
We need to partition nums into subsequences such that:
Each element is in exactly one subsequence
The difference between max and min in any subsequence is ≤ k

Time Complexity:
Sorting: O(n log n)
Traversing: O(n)
Total TC: O(n log n)
*/

//two ways to solve it: without building subsequences:
int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int count = 1; // at least one group
    int start = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - start > k) {
            count++;
            start = nums[i];
        }
    }

    return count;
}

//building subsequences: takes more space
vector<vector<int>> result;
vector<int> current;

sort(nums.begin(), nums.end());
int start = nums[0];
current.push_back(start);

for (int i = 1; i < nums.size(); i++) {
    if (nums[i] - start > k) {
        result.push_back(current);
        current.clear();
        start = nums[i];
    }
    current.push_back(nums[i]);
}
result.push_back(current); // push the last group

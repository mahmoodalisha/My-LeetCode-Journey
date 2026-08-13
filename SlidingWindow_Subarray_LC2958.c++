class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int result = 0; //length of the subarray
        unordered_map<int, int> freq;

        while(j<n){
            freq[nums[j]]++;
            while(i<j && freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};
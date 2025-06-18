//NOTE: If freq[2] = 1, it means:“The number 2 has appeared once so far (or is left only once for intersection)”It has nothing to do with index 2 like an array.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Step 1: Count elements in nums1
        for (int num : nums1) {
            freq[num]++;
        }

        // Step 2: Check in nums2 and build result
        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--; // reduce count
            }
        }

        return result;
    }
};
/*
Input: nums1 = [1, 2, 2, 1] nums2 = [2, 2]
Step 1: Make frequency map from nums1:
freq = {
  1: 2,   // two 1s in nums1
  2: 2    // two 2s in nums1
}

DRY RUN:
👉 First j = 2
freq[2] = 2 → greater than 0 ✅
Push 2 to result
Decrease freq[2] → now freq[2] = 1

👉 Second j = 2 again
freq[2] = 1 → still > 0 ✅
Push 2 to result
Decrease freq[2] → now freq[2] = 0
Now freq = { 1: 2, 2: 0 }

So if any more 2s come in nums2, we skip them (since freq[2] == 0 now).
*/

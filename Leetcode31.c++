#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int k = -1; //here k is the pivot, the point at which we create a new permutation

        // Step 1: Find the largest index k such that nums[k] < nums[k + 1]
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) { //This step finds the position where the order of the array can be adjusted to create the next permutation.
                k = i;
                break;
            }
        }

        if (k == -1) {
            // If no such k exists, reverse the entire array
            // If k remains -1, it means the array is in descending order, which is the last permutation. To get the smallest permutation (the first permutation), reverse the entire array.
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the largest index l greater than k such that nums[k] < nums[l]
        //Iterate from the end of the array (i = n - 1) towards the position just after k (i > k).
        int l = -1;
        for (int i = n - 1; i > k; --i) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }

        // Step 3: Swap nums[k] and nums[l]
        //This swap ensures that the permutation is incremented to the next lexicographical order.
        std::swap(nums[k], nums[l]);

        // Step 4: Reverse the sequence from nums[k + 1] to the end
        // This step reorders the elements after k to be the smallest possible order, thus completing the formation of the next permutation.
        std::reverse(nums.begin() + k + 1, nums.end());
    }
};

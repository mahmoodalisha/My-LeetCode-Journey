class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // Sort the array
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; //the first three elements of the array

        for (int i = 0; i < n - 2; ++i) { // Iterate through each element
            int left = i + 1; // Initialize left pointer
            int right = n - 1; // Initialize right pointer

            while (left < right) { // Two-pointer approach
                int currentSum = nums[i] + nums[left] + nums[right]; // Calculate the sum of the current triplet
                //nums[i]: This is the fixed element in the current iteration of the outer for loop.

                // Update the closest sum if the current sum is closer to the target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // Adjust the pointers based on the comparison with the target
                if (currentSum < target) {
                    ++left; // Move left pointer right to increase the sum
                } else if (currentSum > target) {
                    --right; // Move right pointer left to decrease the sum
                } else {
                    // If the current sum equals the target, return it immediately
                    return currentSum;
                }
            }
        }

        return closestSum; // Return the closest sum after all iterations
    }
};

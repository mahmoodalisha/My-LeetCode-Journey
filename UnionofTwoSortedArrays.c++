/*
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.
The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

Examples:
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
Output: [1, 2, 3, 4, 5, 7]

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
Output: [1, 3, 4, 5, 6, 7, 8, 9]
*/

class Solution {
    public:
        vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
            int i = 0; // Pointer for the first array nums1
            int j = 0; // Pointer for the second array nums2
    
            vector<int> unionArray;
            while (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] <= nums2[j]) {
                    if (unionArray.empty() || unionArray.back() != nums1[i]) {  // Avoid duplicates
                        unionArray.push_back(nums1[i]);
                    }
                    i++;
                } else {
                    if (unionArray.empty() || unionArray.back() != nums2[j]) {  // Avoid duplicates
                        unionArray.push_back(nums2[j]);
                    }
                    j++;
                }
            }

            // Add remaining elements from nums1
            while (i < nums1.size()) {
                if (unionArray.empty() || unionArray.back() != nums1[i]) {  // Avoid duplicates
                    unionArray.push_back(nums1[i]);
                }
                i++;
            }

            // Add remaining elements from nums2
            while (j < nums2.size()) {
                if (unionArray.empty() || unionArray.back() != nums2[j]) {  // Avoid duplicates
                    unionArray.push_back(nums2[j]);
                }
                j++;
            }

            return unionArray;
        }
};
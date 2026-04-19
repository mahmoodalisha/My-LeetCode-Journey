//Since both arrays are sorted in a non-increasing way this means that for each value in the first array. We can find the farthest value smaller than it using binary search.
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int m = nums1.size();
        int n = nums2.size();

        int i = 0; //to iterate in nums1
        int j = 0; //to iterate in nums2

        while(i < m && j < n){
            if(nums1[i] > nums2[j]){
                i++;
            } else{
                result = max(result, j-i);
                j++;
            }
        }
        return result;
    }
};
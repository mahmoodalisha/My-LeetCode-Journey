/*
Agar nums1 = [1, 2, 2, 1],
Toh unordered_set<int> s(nums1.begin(), nums1.end()); ke baad:

s = {1, 2}

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for(int num : nums2){
            if(seen.count(num)){
                result.insert(num);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};
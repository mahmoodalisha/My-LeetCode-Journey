/*
Agar nums1 = [1, 2, 2, 1],
Toh unordered_set<int> s(nums1.begin(), nums1.end()); ke baad:

s = {1, 2}

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> ans;

        for(auto& num : nums){
            if(s.count(num))
            ans.insert(num);
        }
        return (vector<int> ans.begin(), ans.end());
    }
};
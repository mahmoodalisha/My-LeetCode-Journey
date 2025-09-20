class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> finalarray;

        for(int i = 0; i<n; i+=3){//making a grp of 3 elements, so iterate after 3 elements
            if(nums[i+2]-nums[i]>k) return {};
                finalarray.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            return finalarray;
    }
};

//TC = O(nlogn)
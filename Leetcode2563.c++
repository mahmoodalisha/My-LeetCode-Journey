class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            long long count = 0;
    
            for(int i = 0; i<n; i++){
                int low = lower - nums[i];
                int high = upper - nums[i];
    
                //binary search to find j within the range
                auto left = lower_bound(nums.begin() + i + 1, nums.end(), low);  
                auto right = upper_bound(nums.begin() + i + 1, nums.end(), high);
    
                count += (right - left);
            }
            return count;
        }
    }; 
    
    /*  
    The formula goes like this: lower <= nums[i] + nums[j] <= upper
    Rearranged: (lower - nums[i]) <= nums[j] <= (upper - nums[i])
    
    example vector<int> arr = {1, 3, 5, 7, 9};
    auto it = lower_bound(arr.begin(), arr.end(), 5);
    it will point to the element 5 (index 2)
    */
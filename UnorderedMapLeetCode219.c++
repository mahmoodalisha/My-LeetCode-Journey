class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        for(int i = 0; i<nums.size(); i++){
            if(mpp.count(nums[i])){ //nums[i] means the index you see then count it
                if(abs(i-mpp[nums[i]])<=k)
                return true;
            }  
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mpp[nums[i]] = i;
        }
        return false;
    }
}; 